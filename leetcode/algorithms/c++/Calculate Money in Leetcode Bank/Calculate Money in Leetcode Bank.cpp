class Solution
{
public:
    int totalMoney(int n)
    {
        int r = 0;
        int st = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 7 == 0)
                ++st;
            r += st + (i % 7);
        }
        return r;
    }
};