class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        map<int, int> base;
        for (int i = 1; i < 2000 + 100; i++)
        {
            base[i] = 1;
        }
        for (auto &x : arr)
        {
            ++base[x];
        }
        for (auto &x : base)
        {
            if (x.second == 1)
                --k;
            if (k == 0)
                return x.first;
        }
        return 0;
    }
};