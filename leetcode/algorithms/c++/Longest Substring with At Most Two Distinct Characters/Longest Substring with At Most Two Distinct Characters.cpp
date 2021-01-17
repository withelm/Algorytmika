class Solution
{
private:
    map<char, int> base;
    bool check(char x)
    {
        int notZero = 0;
        for (auto &x : base)
        {
            if (x.second > 0)
                ++notZero;
        }
        return notZero <= 1 || (base[x] > 0);
    }

public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int r = 0;
        int begin = 0;
        int end = 0;
        int n = s.size();
        int tmp = 0;
        while (end < n)
        {

            r = max(r, tmp);
            while (end < n && check(s[end]))
            {
                ++tmp;
                ++base[s[end]];
                ++end;
                r = max(r, tmp);
            }
            --tmp;
            r = max(r, tmp);
            --base[s[begin]];
            ++begin;
        }
        return r;
    }
};