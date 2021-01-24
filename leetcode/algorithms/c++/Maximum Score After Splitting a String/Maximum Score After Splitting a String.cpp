class Solution
{
public:
    int maxScore(string s)
    {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 0;

        int cnt0 = s[0] == '0';
        int cnt1 = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
            if (s[i] == '1')
                ++cnt1;
        int res = cnt0 + cnt1;

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
                ++cnt0;
            else
                --cnt1;
            res = max(res, cnt0 + cnt1);
        }
        return res;
    }
};
