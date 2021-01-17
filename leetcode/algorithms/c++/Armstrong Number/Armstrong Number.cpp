class Solution
{
private:
    int length(int x)
    {
        int result = 0;
        while (x > 0)
        {
            ++result;
            x /= 10;
        }
        return result;
    }

public:
    bool isArmstrong(int N)
    {
        int x = N;
        int len = length(x);
        int sum = 0;
        while (x > 0)
        {
            sum += pow(x % 10, len);
            x /= 10;
        }
        return N == sum;
    }
};