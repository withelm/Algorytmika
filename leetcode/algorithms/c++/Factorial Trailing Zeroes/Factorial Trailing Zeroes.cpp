class Solution
{
private:
public:
    int trailingZeroes(int n)
    {
        long long int multi_five = 5, result = 0;
        while (n / multi_five != 0)
        {
            result += n / multi_five;
            multi_five *= 5;
        }
        return result;
    }
};