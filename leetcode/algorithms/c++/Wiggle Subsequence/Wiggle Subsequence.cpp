class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] < nums[j])
                    dp[0][i] = max(dp[0][i], dp[1][j] + 1);
                if (nums[i] > nums[j])
                    dp[1][i] = max(dp[1][i], dp[0][j] + 1);
            }
        }
        return max(dp[0][n - 1], dp[1][n - 1]) + 1;
    }
};