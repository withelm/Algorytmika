class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;

        int bitMask = 0;
        int r = N;
        while (N > 0)
        {
            bitMask *= 2;
            bitMask += 1;
            N /= 2;
        }

        return ~r & bitMask;
    }
};