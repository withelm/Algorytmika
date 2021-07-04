class Solution
{
private:
    int n;
    int INF = 1e9;
    int MX = 30;
    vector<vector<int>> dp;
    string s;

    void init()
    {
        n = s.size();
        dp.resize(MX);
        for (int i = 0; i < MX; i++)
        {
            dp[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = INF;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < MX; j++)
            {
                dp[j][i] = dp[j][i + 1];
            }
            dp[s[i + 1] - 'a'][i] = i + 1;
        }
    }

    bool check(string &word)
    {

        int m = word.size();
        int index = 0;
        int i = (word[0] == s[0]);
        while (i < m)
        {

            index = dp[word[i] - 'a'][index];
            if (index == INF)
                return false;
            ++i;
        }

        return true;
    }

public:
    int numMatchingSubseq(string _s, vector<string> &words)
    {
        s = _s;
        init();
        int res = 0;
        for (auto &word : words)
        {
            res += check(word);
        }
        return res;
    }
};