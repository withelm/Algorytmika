class Solution
{
private:
    vector<vector<int>> dp;
    int n;
    int m = 5;
    int MOD = 1e9 + 7;

public:
    int countVowelPermutation(int _n)
    {
        n = _n;
        dp.resize(m);
        for (int i = 0; i < m; i++)
        {
            dp[i].resize(n);
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = (dp[1][i - 1]) % MOD;
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
            dp[2][i] = (((((dp[0][i - 1] + dp[1][i - 1]) % MOD) + dp[3][i - 1]) % MOD + dp[4][i - 1]) % MOD) % MOD;
            dp[3][i] = (dp[2][i - 1] + dp[4][i - 1]) % MOD;
            dp[4][i] = (dp[0][i - 1]) % MOD;
        }

        return ((((((dp[0][n - 1] + dp[1][n - 1]) % MOD) + dp[2][n - 1]) % MOD + dp[3][n - 1]) % MOD) + dp[4][n - 1]) % MOD;
    }
};