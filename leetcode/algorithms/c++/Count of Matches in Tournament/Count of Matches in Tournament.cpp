class Solution
{
public:
    int numberOfMatches(int n)
    {
        if (n == 0)
            return -1;
        if (n % 2 == 0)
            return numberOfMatches(n / 2) + n / 2;
        return numberOfMatches(n - 1) + 1;
    }
};