class Solution
{
private:
    int MOD = 1e9 + 7;
    int binaryLen(int x)
    {
        int r = 0;
        while (x > 0)
        {
            ++r;
            x /= 2;
        }
        return r;
    }

public:
    int concatenatedBinary(int n)
    {
        long long int r = 0;
        for (int i = 1; i <= n; i++)
        {
            int len = binaryLen(i);

            r = (r << len) % MOD;
            r = (r + i) % MOD;
        }
        return r % MOD;
    }
};