class Solution
{
public:
    int arrangeCoins(int n)
    {

        int val = 1;
        while (n - val >= 0)
        {
            n -= val;
            ++val;
        }

        return val - 1;
    }
};