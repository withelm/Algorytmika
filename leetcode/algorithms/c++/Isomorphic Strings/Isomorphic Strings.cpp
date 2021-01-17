class Solution
{
private:
    bool check(string &s, string &t)
    {
        map<int, int> base;
        int n = t.size();
        if (n != s.size())
            return false;

        for (int i = 0; i < n; i++)
        {
            if (base.find(s[i]) == base.end())
            {
                base[s[i]] = s[i] - t[i];
            }
            else
            {
                if (base[s[i]] != s[i] - t[i])
                    return false;
            }
        }

        return true;
    }

public:
    bool isIsomorphic(string s, string t)
    {
        return check(s, t) && check(t, s);
    }
};