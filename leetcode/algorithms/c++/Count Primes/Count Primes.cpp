class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> vp(n + 1, false);
        if (n < 2)
            return 0;
        int result = 0;
        for (int i = 2; i < n; i++)
        {
            if (!vp[i])
            {
                ++result;
                for (int j = i + i; j <= n; j += i)
                {
                    vp[j] = true;
                }
            }
        }
        return result;
    }
};