class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (auto &x : nums)
            res += abs(nums[nums.size() / 2] - x);
        return res;
    }
};