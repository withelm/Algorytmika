class Solution
{
public:
    int tab[255];

    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        for (int i = 0; i < 255; i++)
            tab[i] = 0;

        int result = 1;
        int begin = 0;
        int end = 1;
        ++tab[s[begin]];
        while (begin < s.size())
        {
            if (begin >= end)
            {
                end = begin + 1;
                for (int i = 0; i < 255; i++)
                    tab[i] = 0;
                ++tab[s[begin]];
            }
            while (end < s.size() && check(s[end]))
            {

                ++tab[s[end]];
                ++end;
            }

            int val = end - begin;
            if (val > result)
                result = val;

            --tab[s[begin]];

            ++begin;
        }

        return result;
    }

    bool check(char x)
    {
        if (tab[x] > 0)
            return false;
        return true;
    }
};