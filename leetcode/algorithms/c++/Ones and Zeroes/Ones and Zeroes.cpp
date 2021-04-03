class Solution
{
private:
    vector<vector<int>> dp;

    map<string, vector<int>> base;

    vector<int> calc(string &x)
    {
        vector<int> r(2, 0);
        for (auto &i : x)
        {
            ++r[i - '0'];
        }
        return r;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        for (auto &item : strs)
            base[item] = calc(item);

        dp.resize(m + 1);
        for (auto &i : dp)
        {
            i.resize(n + 1);
            for (auto &j : i)
            {
                j = 0;
            }
        }

        for (auto &item : strs)
        {
            auto cnt = base[item];
            for (int _m = m; _m >= cnt[0]; --_m)
            {
                for (int _n = n; _n >= cnt[1]; --_n)
                {
                    dp[_m][_n] = max(1 + dp[_m - cnt[0]][_n - cnt[1]], dp[_m][_n]);
                }
            }
        }

        return dp[m][n];
    }
};