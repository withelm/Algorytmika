class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
            return false;
        long long int v = 1;
        while (v < n)
            v *= 3;
        return v == n;
    }
};