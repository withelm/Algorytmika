class Solution
{

public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        long long int pow10 = 1;
        int K = 1;
        while (n >= pow10 * 10)
        {
            pow10 *= 10;
            ++K;
        }

        vector<int> dp(K + 1, 0);
        dp[K] = 1;
        int n_tmp = n;
        int i = K - 1;
        while (n_tmp > 0)
        {
            int Si = n_tmp % 10;
            for (auto &d : digits)
            {
                int d_val = d[0] - '0';
                if (d_val < Si)
                {
                    dp[i] += pow(digits.size(), K - i - 1);
                }
                else if (d_val == Si)
                {
                    dp[i] += dp[i + 1];
                }
            }
            --i;
            n_tmp /= 10;
        }

        int r = 0;
        for (int i = 1; i < K; i++)
            r += pow(digits.size(), i);
        return dp[0] + r;
    }
};