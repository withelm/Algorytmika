class Solution
{
public:
    int reachNumber(int t)
    {
        t = abs(t);
        int n = 0;
        int sum = 0;
        while (sum < t)
        {
            sum += ++n;
        }
        while ((sum - t) % 2 != 0)
        {
            sum += ++n;
        }
        return n;
    }
};