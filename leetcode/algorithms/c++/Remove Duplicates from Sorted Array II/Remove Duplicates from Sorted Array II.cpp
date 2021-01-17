class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int prev2 = -1;
        int prev1 = -1;
        int acc = -1;
        if (nums.size() <= 2)
            return nums.size();
        prev2 = nums[0];
        prev1 = nums[1];
        for (int i = 2; i < nums.size();)
        {
            if (prev2 == prev1 && prev1 == nums[i])
            {
                nums.erase(nums.begin() + i);
                continue;
            }
            else
            {
                prev2 = prev1;
                prev1 = nums[i];
                ++i;
            }
        }
        return nums.size();
    }
};