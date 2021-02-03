class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    r = dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else if (dp[i - 1][j] == dp[i][j - 1])
                    {
                        int k = dp[i - 1][j];
                        dp[i][j] = k + (matrix[i - k][j - k] == '1');
                    }
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
                r = max(r, dp[i][j]);
            }
        }
        return r * r;
    }
};