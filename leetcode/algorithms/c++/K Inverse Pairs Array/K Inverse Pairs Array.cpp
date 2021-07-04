class Solution
{
private:
    int dp[1001][1001];
    int MOD = 1e9 + 7;

public:
    int kInversePairs(int n, int k)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    int val = 0;
                    if (j - i >= 0)
                        val -= dp[i - 1][j - i];
                    val = (val + dp[i - 1][j] + MOD) % MOD;
                    dp[i][j] = (dp[i][j - 1] + val) % MOD;
                }
            }
        }
        int res = 0;
        if (k > 0)
            res = -dp[n][k - 1];
        return (dp[n][k] + MOD + res) % MOD;
    }
};