class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> dic;
        for (auto &x : wordDict)
            dic.insert(x);
        int n = s.size();
        vector<bool> t(n + 1, false);
        t[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (t[j] && dic.find(s.substr(j, i - j)) != dic.end())
                {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n];
    }
};