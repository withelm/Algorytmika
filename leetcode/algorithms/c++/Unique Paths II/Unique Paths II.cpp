class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));

        int default_val = 1;
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                default_val = 0;
            dp[i][0] = default_val;
        }
        default_val = 1;
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                default_val = 0;
            dp[0][i] = default_val;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};