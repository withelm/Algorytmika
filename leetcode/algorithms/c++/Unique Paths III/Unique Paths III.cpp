class Solution
{
private:
    int n, m;
    int dfs(vector<vector<int>> &g, int x, int y, int acc, int limit)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == -1)
            return 0;
        if (g[x][y] == 2)
            return acc == limit;
        g[x][y] = -1;
        int val = dfs(g, x + 1, y, acc + 1, limit) +
                  dfs(g, x - 1, y, acc + 1, limit) +
                  dfs(g, x, y + 1, acc + 1, limit) +
                  dfs(g, x, y - 1, acc + 1, limit);
        g[x][y] = 0;
        return val;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int x, y, steps = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                if (grid[i][j] != -1)
                    ++steps;
            }
        }
        return dfs(grid, x, y, 1, steps);
    }
};