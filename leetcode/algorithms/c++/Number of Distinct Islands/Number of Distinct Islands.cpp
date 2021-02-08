class Solution
{
private:
    int n, m;
    map<vector<vector<int>>, int> base;
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid;

    vector<vector<int>> dfs(int x, int y)
    {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return {};
        if (grid[x][y] == 0)
            return {};
        grid[x][y] = 0;

        vector<vector<int>> r = {{x, y}};
        for (auto &move : moves)
        {
            auto tmp = dfs(x + move[0], y + move[1]);
            for (auto &i : tmp)
            {
                r.push_back(i);
            }
        }
        return r;
    }

public:
    int numDistinctIslands(vector<vector<int>> &tab)
    {
        grid = tab;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    // cout << i << " " << j << endl;
                    auto k = dfs(i, j);
                    sort(k.begin(), k.end());
                    for (auto &x : k)
                    {
                        x[0] -= i;
                        x[1] -= j;
                    }
                    ++base[k];
                }
            }
        }
        return base.size();
    }
};