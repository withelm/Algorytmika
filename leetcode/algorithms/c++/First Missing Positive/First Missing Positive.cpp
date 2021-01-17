class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;
        sort(nums.begin(), nums.end());
        int index = 0;
        while (index < nums.size() && nums[index] < 0)
            ++index;
        if (index == nums.size() || nums[index] > 1)
            return 1;
        int begin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - begin > 1 && nums[i] - 1 > 0)
                return begin + 1;
            begin = nums[i];
        }
        if (nums.back() + 1 <= 0)
            return 1;
        return nums.back() + 1;
    }
};