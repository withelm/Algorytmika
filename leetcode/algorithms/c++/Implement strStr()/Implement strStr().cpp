class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() == 0 && needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if (check(haystack, needle, i))
                return i;
        }
        return -1;
    }
    bool check(string x, string y, int begin)
    {
        for (int i = 0; i < y.size(); i++)
        {
            if (x[i + begin] != y[i])
                return false;
        }
        return true;
    }
};