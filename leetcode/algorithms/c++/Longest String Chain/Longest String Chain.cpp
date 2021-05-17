class Solution
{
private:
    bool check(string &x, string &y)
    {
        int i = 0;
        int j = 0;
        int m = x.size();
        int n = y.size();
        bool isCheck = false;
        if (n != m + 1)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (y[i] == x[j])
                ++j;
            else
            {
                if (!isCheck)
                    isCheck = true;
                else
                    return false;
            }
        }
        return true;
    }

    vector<int> dp;
    int n;

public:
    int longestStrChain(vector<string> &words)
    {

        sort(words.begin(), words.end(),
             [](const string &x, const string &y) {
                 return x.size() < y.size();
             });
        n = words.size();
        dp.resize(n);
        for (auto &x : dp)
            x = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};