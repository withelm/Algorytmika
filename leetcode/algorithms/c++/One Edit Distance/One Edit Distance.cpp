class Solution
{
private:
    bool checkInsert(string &s, string &t)
    {
        if (s.size() + 1 != t.size())
            return false;
        int n = s.size();
        int index = 0;
        while (index < n && s[index] == t[index])
        {
            ++index;
        }
        ++index;
        while (index - 1 < n && s[index - 1] == t[index])
        {
            ++index;
        }

        return index == t.size();
    }

    bool checkReplace(string &s, string &t)
    {
        if (s.size() != t.size())
            return false;
        int diff = 0;
        for (int i = 0; i < s.size(); i++)
        {
            diff += s[i] != t[i];
        }
        return diff == 1;
    }

public:
    bool isOneEditDistance(string s, string t)
    {
        if (s == t)
            return false;
        return checkInsert(s, t) || checkInsert(t, s) || checkReplace(s, t);
    }
};