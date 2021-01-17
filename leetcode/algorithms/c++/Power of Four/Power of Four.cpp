class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num < 1)
            return false;

        long long int val = 1;
        while (val < num)
            val *= 4;
        return val == num;
    }
};