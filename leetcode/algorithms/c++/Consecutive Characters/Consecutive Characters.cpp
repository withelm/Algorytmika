class Solution
{
public:
    int maxPower(string s)
    {
        char old = 0;
        int r = 0;
        int rr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (old != s[i])
            {
                r = max(r, rr);
                old = s[i];
                rr = 1;
            }
            else
            {
                ++rr;
            }
        }
        return max(r, rr);
    }
};