class Point
{
public:
    int x, y, dist;
};

struct CustomCompare
{
    bool operator()(const Point &lhs, const Point &rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

class Solution
{
private:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    map<vector<int>, vector<int>> next;
    int n, m;
    vector<vector<int>> maze;
    vector<vector<int>> distance;
    int INF = 1e7;
    priority_queue<Point, vector<Point>, CustomCompare> q;

    void init()
    {
        for (auto &row : maze)
        {
            row.push_back(1);
            row.insert(row.begin(), 1);
        }
        vector<int> fullOne(maze[0].size(), 1);
        maze.push_back(fullOne);
        maze.insert(maze.begin(), fullOne);
        n = maze.size();
        m = maze[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 1)
                {
                    for (int k = 0; k < moves.size(); k++)
                    {
                        next[{i, j, k}] = {i, j};
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            distance.push_back({});
            for (int j = 0; j < m; j++)
            {
                distance[i].push_back(INF);
                if (maze[i][j] == 0)
                {
                    if (maze[i][j - 1] == 1)
                        next[{i, j, 0}] = {i, j};
                    else
                        next[{i, j, 0}] = next[{i, j - 1, 0}];
                    if (maze[i - 1][j] == 1)
                        next[{i, j, 2}] = {i, j};
                    else
                        next[{i, j, 2}] = next[{i - 1, j, 2}];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (maze[i][j] == 0)
                {
                    if (maze[i][j + 1] == 1)
                        next[{i, j, 1}] = {i, j};
                    else
                        next[{i, j, 1}] = next[{i, j + 1, 1}];
                    if (maze[i + 1][j] == 1)
                        next[{i, j, 3}] = {i, j};
                    else
                        next[{i, j, 3}] = next[{i + 1, j, 3}];
                }
            }
        }
    }
    inline int calc(const Point &x, const vector<int> &y)
    {
        return abs(x.x - y[0]) + abs(x.y - y[1]);
    }

public:
    int shortestDistance(vector<vector<int>> &_maze, vector<int> &start, vector<int> &destination)
    {
        maze = _maze;
        init();

        start[0] += 1;
        start[1] += 1;
        destination[0] += 1;
        destination[1] += 1;
        Point start_tmp;
        start_tmp.x = start[0];
        start_tmp.y = start[1];
        start_tmp.dist = 0;
        q.push(start_tmp);

        distance[start[0]][start[1]] = 0;

        while (!q.empty())
        {
            auto item = q.top();
            q.pop();

            //cout << item.x << " " << item.y << " " << item.dist << endl;
            if (item.x == destination[0] && item.y == destination[1])
            {
                return item.dist;
            }
            for (int i = 0; i < 4; i++)
            {
                auto pnt = next[{item.x, item.y, i}];
                // cout << "> " << pnt[0] << " " << pnt[1] << endl;
                if (item.dist + calc(item, pnt) < distance[pnt[0]][pnt[1]])
                {
                    start_tmp.x = pnt[0];
                    start_tmp.y = pnt[1];
                    start_tmp.dist = item.dist + calc(item, pnt);
                    distance[pnt[0]][pnt[1]] = start_tmp.dist;
                    q.push(start_tmp);
                }
            }
        }

        return -1;
    }
};