class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a.size() > b.size())
            return a.size();
        if (a.size() == b.size() && a != b)
            return a.size();
        if (a == b)
            return -1;

        return max(a.size(), b.size());
    }
};