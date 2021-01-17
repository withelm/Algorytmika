class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int result = 0;
        while (n > 0)
        {
            result += n % 2;
            n /= 2;
        }
        return result == 1;
    }
};