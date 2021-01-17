class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto &x : nums)
            sum += x;
        vector<int> r;
        int sum2 = 0;
        int index = nums.size() - 1;
        while (index >= 0 && sum2 <= sum)
        {
            sum2 += nums[index];
            r.push_back(nums[index]);
            sum -= nums[index];
            --index;
        }
        return r;
    }
};