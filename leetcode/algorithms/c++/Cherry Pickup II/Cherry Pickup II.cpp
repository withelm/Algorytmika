class Solution
{
private:
    vector<vector<int>> moves{
        {-1, -1, -1},
        {-1, -1, 0},
        {-1, -1, 1},
        {-1, 0, -1},
        {-1, 0, 0},
        {-1, 0, 1},
        {-1, 1, -1},
        {-1, 1, 0},
        {-1, 1, 1}};
    int n, m;

    bool check(int j, int k, vector<int> &mv)
    {

        if (j + mv[1] < 0 || j + mv[1] >= n)
            return false;
        if (k + mv[2] < 0 || k + mv[2] >= n)
            return false;
        //       cout << i + mv[0] << " " << j + mv[1] << " " << k + mv[2] << endl;
        return true;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        if (n - 1 == 0)
        {
            dp[0][0][n - 1] = grid[0][n - 1];
        }
        else
        {
            dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < min(n, i + 1); j++)
            {
                for (int k = max(0, n - 1 - i); k < n; k++)
                {
                    int tmp = 0;
                    for (auto &x : moves)
                    {
                        if (check(j, k, x))
                            tmp = max(tmp, dp[i + x[0]][j + x[1]][k + x[2]]);
                    }

                    if (k != j)
                    {
                        dp[i][j][k] = tmp + grid[i][j] + grid[i][k];
                    }
                    else
                    {
                        dp[i][j][k] = tmp + grid[i][j];
                    }
                }
            }
        }
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                result = max(result, dp[m - 1][i][j]);
            }
        }

        return result;
    }
};