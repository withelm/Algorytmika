class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num < 0)
            return false;
        long long int i = 0;
        while (i * i < num)
            ++i;
        return i * i == num;
    }
};