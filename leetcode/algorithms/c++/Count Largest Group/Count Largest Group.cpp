class Solution
{
private:
    int sum_dig(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r += x % 10;
            x /= 10;
        }
        return r;
    }

public:
    int countLargestGroup(int n)
    {
        map<int, int> base;
        for (int i = 1; i <= n; i++)
        {
            ++base[sum_dig(i)];
        }
        int len = 0;
        int val = 0;
        for (auto &x : base)
        {
            if (x.second > len)
            {
                len = x.second;
                val = 1;
            }
            else if (x.second == len)
            {
                ++val;
            }
        }
        return val;
    }
};