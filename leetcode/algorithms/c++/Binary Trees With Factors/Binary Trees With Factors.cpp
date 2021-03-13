class Solution
{
private:
    int MOD = 1000000007;

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        map<int, long long int> base;
        sort(arr.begin(), arr.end());
        for (auto &x : arr)
            base[x] = 1;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int tmp = arr[i] / arr[j];
                    base[arr[i]] = (base[arr[i]] + base[arr[j]] * base[tmp]) % MOD;
                }
            }
        }
        int r = 0;
        for (auto &x : base)
        {
            r = (r + x.second) % MOD;
        }
        return r;
    }
};