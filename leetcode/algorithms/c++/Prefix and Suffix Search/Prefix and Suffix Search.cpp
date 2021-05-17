class WordFilter
{
private:
    map<string, int> dp;
    int n;

public:
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        int index = 0;
        for (auto &word : words)
        {
            int m = word.size();
            for (int i = 1; i <= m; i++)
            {
                string pref = word.substr(0, i);
                for (int j = 0; j < m; j++)
                {
                    dp[pref + "#" + word.substr(j, m)] = index + 1;
                }
            }
            ++index;
        }
    }

    int f(string prefix, string suffix)
    {

        return dp[prefix + "#" + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */