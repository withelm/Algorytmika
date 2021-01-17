class Solution
{
private:
    vector<vector<bool>> vis;
    vector<vector<int>> maze_source;
    int n, m;
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int x, int y)
    {
        if (x < 0 || x > n || y < 0 || y > m)
            return;
        if (vis[x][y])
            return;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int tmp_x = x;
            int tmp_y = y;
            while (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m && maze_source[tmp_x][tmp_y] == 0)
            {
                tmp_x += move[i][0];
                tmp_y += move[i][1];
            }
            dfs(tmp_x - move[i][0], tmp_y - move[i][1]);
        }
    }

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        n = maze.size();
        m = maze[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        maze_source = maze;
        dfs(start[0], start[1]);

        return vis[destination[0]][destination[1]];
    }
};