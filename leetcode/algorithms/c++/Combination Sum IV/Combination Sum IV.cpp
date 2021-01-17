class Solution
{
private:
    long long int MOD = 2000000007;

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<long long int> t(target + 1, 0);
        t[0] = 0;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - nums[j] >= 0)
                {
                    t[i] += t[i - nums[j]];
                }
                if (i == nums[j])
                    ++t[i];
                t[i] = t[i] % MOD;
            }
        }

        return t[target];
    }
};