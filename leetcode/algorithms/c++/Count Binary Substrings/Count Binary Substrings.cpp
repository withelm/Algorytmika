class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        if (s.size() == 0)
            return 0;

        vector<int> t;
        char last = s[0];
        int val = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (last == s[i])
            {
                ++val;
            }
            else
            {
                last = s[i];
                t.push_back(val);
                val = 1;
            }
        }
        t.push_back(val);

        int r = 0;
        for (int i = 0; i + 1 < t.size(); i++)
        {
            r += min(t[i], t[i + 1]);
        }
        return r;
    }
};