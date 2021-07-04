class Solution
{
private:
    int n;
    vector<vector<int>> dp;
    vector<int> s;
    int dfs(int left, int right, int sum)
    {
        if (left == right)
            return 0;
        if (dp[left][right] != 0)
            return dp[left][right];
        return dp[left][right] = max(sum - s[left] - dfs(left + 1, right, sum - s[left]), sum - s[right] - dfs(left, right - 1, sum - s[right]));
    }

public:
    int stoneGameVII(vector<int> &stones)
    {
        s = stones;
        int n = s.size();

        int sum = 0;
        for (auto &item : s)
            sum += item;

        dp.resize(n);
        for (auto &row : dp)
        {
            row.resize(n);
        }

        dfs(0, n - 1, sum);
        return dp[0][n - 1];
    }
};