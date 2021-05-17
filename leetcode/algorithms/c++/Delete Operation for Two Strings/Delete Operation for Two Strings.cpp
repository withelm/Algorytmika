class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size() + 1;
        int m = word2.size() + 1;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n + m - dp[n - 1][m - 1] * 2 - 2;
    }
};