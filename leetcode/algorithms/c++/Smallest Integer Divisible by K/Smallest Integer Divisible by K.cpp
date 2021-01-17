class Solution
{
public:
    int smallestRepunitDivByK(int K)
    {
        if (K % 2 == 0 || K % 5 == 0)
            return -1;
        if (K == 1)
            return 1;
        int i = 1;
        int val = 1;
        while (val != 0)
        {
            val = ((val * 10) + 1) % K;
            ++i;
        }
        return i;
    }
};