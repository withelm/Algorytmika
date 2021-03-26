class Solution
{
private:
    int MOD = 1e9 + 7;
    map<int, long long int> base;
    long long int calc(long long int n)
    {
        return (n * (n - 1)) / 2;
    }
    long long int calc2(long long int n)
    {
        return (n * (n - 1) * (n - 2)) / 6;
    }

public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        for (auto &x : arr)
            ++base[x];
        long long int r = 0;
        for (int i = 0; i <= 100; i++)
        {
            for (int j = i; j <= 100; j++)
            {
                int k = target - i - j;

                if (j <= k)
                {
                    if (i != j && j != k)
                        r = (r + base[i] * base[j] * base[k]) % MOD;
                    if (i != j && j == k)
                        r = (r + base[i] * calc(base[j])) % MOD;
                    if (i == j && j != k)
                        r = (r + calc(base[j]) * base[k]) % MOD;
                    if (i == j && j == k)
                        r = (r + calc2(base[i])) % MOD;
                }
            }
        }
        return r;
    }
};