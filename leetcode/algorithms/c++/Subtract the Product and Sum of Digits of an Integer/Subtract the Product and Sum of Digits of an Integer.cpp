class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;
        int ilo = 1;
        while (n != 0)
        {
            sum += n % 10;
            ilo *= n % 10;
            n /= 10;
        }
        return ilo - sum;
    }
};