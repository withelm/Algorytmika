class Solution
{
private:
    int n;
    int INF = 1e9;
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int x, int y, vector<vector<int>> &g, int k)
    {
        // cout << x << " " <<  y <<  " " << k << endl;
        if (x < 0 || y < 0 || x >= n || y >= n)
            return;

        if (g[x][y] > k)
        {
            return;
        }
        g[x][y] = INF;
        for (auto &move : moves)
        {
            dfs(x + move[0], y + move[1], g, k);
        }
    }

    bool check(vector<vector<int>> grid, int k)
    {
        dfs(0, 0, grid, k);
        return grid[n - 1][n - 1] == INF;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        n = grid.size();
        for (int i = max(grid[0][0], grid[n - 1][n - 1]); i <= n * n; i++)
        {
            if (check(grid, i))
            {
                return i;
            }
        }
        return -1;
    }
};