class Solution
{
public:
    string modifyString(string s)
    {
        vector<bool> v(300, false);
        int n = s.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '?')
            {

                v[s[i - 1]] = true;
                v[s[i + 1]] = true;
                for (char k = 'a'; k <= 'z'; k++)
                {
                    if (!v[k])
                    {
                        s[i] = k;
                        break;
                    }
                }
                v[s[i - 1]] = false;
                v[s[i + 1]] = false;
            }
        }
        if (s[0] == '?')
        {
            if (s.size() > 1 && s[1] == 'a')
                s[0] = 'b';
            if (s.size() > 1 && s[1] != 'a')
                s[0] = 'a';
            if (s.size() == 1)
                s[0] = 'a';
        }
        if (s[n - 1] == '?')
        {
            if (s.size() > 1 && s[n - 2] == 'a')
                s[n - 1] = 'b';
            if (s.size() > 1 && s[n - 2] != 'a')
                s[n - 1] = 'a';
        }
        return s;
    }
};