class Solution
{
public:
    string boldWords(vector<string> &words, string S)
    {
        int n = S.size();
        vector<bool> vis(n + 1, false);

        for (auto &x : words)
        {
            int m = x.size();
            for (int i = 0; i <= n - m; i++)
            {
                bool isOk = true;
                for (int j = 0; j < m; j++)
                {
                    if (S[i + j] != x[j])
                        isOk = false;
                }
                if (isOk)
                {
                    for (int j = 0; j < m; j++)
                        vis[i + j] = true;
                }
            }
        }
        string b = "<b>";
        string e = "</b>";
        string r = "";
        bool isOn = false;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                if (isOn)
                {
                    r += S[i];
                }
                else
                {
                    r += b;
                    r += S[i];
                    isOn = true;
                }
            }
            else
            {
                if (isOn)
                {
                    r += e;
                    r += S[i];
                    isOn = false;
                }
                else
                {
                    r += S[i];
                }
            }
        }
        if (isOn)
            r += e;

        return r;
    }
};