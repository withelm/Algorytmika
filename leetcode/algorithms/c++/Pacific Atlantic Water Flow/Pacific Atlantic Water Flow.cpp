class Solution
{
private:
    int n, m;
    map<vector<int>, int> base;

    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isLegal(vector<int> &item, vector<int> &move)
    {
        int x = item[0] + move[0];
        int y = item[1] + move[1];
        if (x < 0 || y < 0 || x >= n || y >= m)
        {
            return false;
        }
        return true;
    }

    void calc(vector<vector<int>> &t, vector<vector<int>> q)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (auto &item : q)
        {
            vis[item[0]][item[1]] = 1;
            ++base[item];
        }

        while (q.size() > 0)
        {
            vector<vector<int>> tmp;
            for (auto &item : q)
            {
                for (auto &move : moves)
                {
                    if (isLegal(item, move))
                    {
                        int x = item[0] + move[0];
                        int y = item[1] + move[1];
                        //cout << item[0] << "-" << item[1] << " " << x << "-" << y << " " << vis[x][y] << endl;
                        if (t[item[0]][item[1]] <= t[x][y] && vis[x][y] == 0)
                        {
                            tmp.push_back({x, y});
                            ++base[{x, y}];
                            vis[x][y] = 1;
                        }
                    }
                }
            }
            q = tmp;
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        if (n == 0)
            return {};
        m = matrix[0].size();

        vector<vector<int>> q;

        for (int i = 0; i < n; i++)
        {
            q.push_back({i, 0});
        }
        for (int i = 1; i < m; i++)
        {
            q.push_back({0, i});
        }
        calc(matrix, q);
        q.clear();
        for (int i = 0; i < n; i++)
        {
            q.push_back({i, m - 1});
        }
        for (int i = 0; i < m - 1; i++)
        {
            q.push_back({n - 1, i});
        }
        calc(matrix, q);
        vector<vector<int>> r;
        for (auto &x : base)
            if (x.second == 2)
                r.push_back(x.first);
        return r;
    }
};