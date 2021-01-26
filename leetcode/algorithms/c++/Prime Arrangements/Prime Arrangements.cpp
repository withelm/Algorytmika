class Solution
{
private:
    int MOD = 1e9 + 7;
    long long int calc(int x)
    {
        if (x == 0)
            return 1;
        return (x * calc(x - 1)) % MOD;
    }

public:
    int numPrimeArrangements(int n)
    {
        vector<bool> prime(n + 1, false);
        prime[0] = true;
        prime[1] = true;
        for (int i = 2; i < n + 1; i++)
        {
            if (!prime[i])
            {
                for (int j = i + i; j < n + 1; j += i)
                    prime[j] = true;
            }
        }

        int cntPrime = 0;
        int cntNoPrime = 0;
        for (int i = 1; i <= n; i++)
            if (prime[i])
                ++cntNoPrime;
            else
            {
                ++cntPrime;
            }

        return (calc(cntPrime) * calc(cntNoPrime)) % MOD;
    }
};