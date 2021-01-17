class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;

        int bitMask = 0;
        int r = num;
        while (num > 0)
        {
            bitMask *= 2;
            bitMask += 1;
            num /= 2;
        }

        return ~r & bitMask;
    }
};