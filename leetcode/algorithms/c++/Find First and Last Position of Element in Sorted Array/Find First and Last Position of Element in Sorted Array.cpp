class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int f = -1;
        int s = -1;
        int n = nums.size();
        int i = 0;
        while (i < n && nums[i] < target)
        {
            ++i;
        }
        if (i >= n)
            return {f, s};
        if (nums[i] != target)
            return {f, s};
        f = i;
        while (i < n && nums[i] == target)
        {
            ++i;
        }
        s = i - 1;
        return {f, s};
    }
};