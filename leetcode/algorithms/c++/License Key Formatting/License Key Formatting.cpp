class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string w = "";
        for (auto &x : S)
        {
            if (x != '-')
                w += x;
        }
        reverse(w.begin(), w.end());
        string r = "";
        int n = w.size();
        int index = 0;
        while (index < n)
        {
            for (int i = 0; i + index < n && i < K; i++)
            {
                if (w[index + i] >= 'a' && w[index + i] <= 'z')
                {
                    r += w[index + i] - 'a' + 'A';
                }
                else
                    r += w[index + i];
            }
            index += K;
            r += "-";
        }
        reverse(r.begin(), r.end());
        if (r[0] == '-')
            r.erase(r.begin());
        return r;
    }
};