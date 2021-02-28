class Solution
{
public:
    int divide(long long int dividend, long long int divisor)
    {
        bool isMinus = false;
        if (dividend >= 0 && divisor < 0)
            isMinus = true;
        if (dividend < 0 && divisor >= 0)
            isMinus = true;
        if (dividend == -2147483648 && divisor == -1)
            return 2147483647;
        if (dividend == -2147483648 && divisor == 1)
            return -2147483648;

        dividend = abs(dividend);
        divisor = abs(divisor);

        if (dividend < divisor)
            return 0;
        if (dividend == divisor)
            if (isMinus)
                return -1;
            else
                return 1;

        vector<long long int> memo;

        long long int curr = divisor;
        while (dividend >= curr)
        {
            memo.push_back(curr);

            curr = curr << 1;
        }

        int n = memo.size() - 1;
        long long int r = 0;
        while (n >= 0)
        {

            if (dividend >= memo[n])
            {
                r += ((long long int)1) << n;
                dividend -= memo[n];
            }
            --n;
        }

        if (isMinus)
            return -r;
        return r;
    }
};