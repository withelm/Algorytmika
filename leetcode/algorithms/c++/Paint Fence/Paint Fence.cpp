class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        vector<int> dp(n, 1);
        dp[1] = k;
        for (int col = 2; col < n; col++)
        {
            dp[col] = dp[col - 1] * (k - 1) + dp[col - 2] * (k - 1);
        }

        return dp[n - 1] * k;
    }
};