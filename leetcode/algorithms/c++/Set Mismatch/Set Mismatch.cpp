class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> b(n + 10, 0);
        for (auto &x : nums)
            ++b[x];
        int v1 = 0;
        int v2 = 1;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 2)
                v1 = i;
            if (b[i] == 0)
                v2 = i;
        }
        return {v1, v2};
    }
};