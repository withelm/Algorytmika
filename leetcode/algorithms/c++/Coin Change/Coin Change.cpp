class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 1e6);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; i++)
        {
            if (dp[i] < 1e6)
            {
                for (auto &j : coins)
                {
                    long long int index = (long long int)i + (long long int)j;
                    if (index < amount + 1)
                        dp[index] = min(dp[index], dp[i] + 1);
                }
            }
        }
        return dp[amount] == 1e6 ? -1 : dp[amount];
    }
};