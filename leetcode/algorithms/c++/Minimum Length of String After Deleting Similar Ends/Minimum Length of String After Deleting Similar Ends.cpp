class Solution
{
public:
    int minimumLength(string s)
    {
        if (s.size() == 1)
            return 1;
        int n = s.size();
        int begin = 0;
        int end = n - 1;
        int lastLen = -1;
        vector<vector<int>> base;
        while (begin < end && s[begin] == s[end])
        {
            lastLen = end - begin;

            auto tmp = s[begin];

            base.push_back({tmp, begin, end, lastLen});
            while (begin < end && tmp == s[begin])
                ++begin;
            while (end > begin && tmp == s[end])
                --end;
        }
        if (begin != end)
            return end - begin + 1;

        if (begin == end)
        {
            auto last = base.back();
            if (s[begin] == s[last[1]])
                return 0;
            return 1;
        }
        return 0;
    }
};