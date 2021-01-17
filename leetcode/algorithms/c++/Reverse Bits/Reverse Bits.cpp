class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        vector<int> v(40, 0);
        uint32_t r = 0;
        int index = 0;

        while (n > 0)
        {
            v[index++] = n % 2;
            n /= 2;
        }

        uint32_t p2 = 1;
        for (int i = 31; i >= 0; i--)
        {
            r += p2 * v[i];
            p2 *= 2;
        }

        return r;
    }
};