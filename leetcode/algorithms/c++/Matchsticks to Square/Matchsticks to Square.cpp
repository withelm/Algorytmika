class Solution
{
private:
    int s;
    vector<int> matchsticks;
    int n;

    map<vector<int>, bool> dp;

    bool dfs(int v, int val)
    {
        int total = 0;
        auto key = {v, val};
        for (int i = n - 1; i >= 0; i--)
        {
            if ((v & (1 << i)) == 0)
                total += matchsticks[n - 1 - i];
        }
        if (total > 0 && total % s == 0)
            ++val;
        if (val == 3)
            return dp[key] = true;
        if (dp.find(key) != dp.end())
            return dp[key];
        bool ans = false;
        int c = total / s;
        int rem = s * (c + 1) - total;

        for (int i = n - 1; i >= 0; i--)
            if (matchsticks[n - 1 - i] <= rem && (v & (1 << i)) > 0)
                if (dfs(v ^ (1 << i), val))
                    return dp[key] = true;
        return dp[key] = false;
    }

public:
    bool makesquare(vector<int> &_matchsticks)
    {
        int sum = 0;
        matchsticks = _matchsticks;
        n = matchsticks.size();
        for (auto &item : matchsticks)
            sum += item;
        if (sum % 4 != 0)
            return false;
        s = sum / 4;

        return dfs((1 << n) - 1, 0);
    }
};