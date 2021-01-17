class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        if (n == 0)
            return true;
        int lastBit = n % 2;
        n /= 2;
        while (n > 0)
        {
            if (lastBit == n % 2)
                return false;
            lastBit = n % 2;
            n /= 2;
        }
        return true;
    }
};