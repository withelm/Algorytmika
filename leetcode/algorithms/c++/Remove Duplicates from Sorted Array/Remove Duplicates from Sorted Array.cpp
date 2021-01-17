class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int result = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size();)
        {
            if (last != nums[i])
            {
                ++result;
                last = nums[i];
                ++i;
            }
            else
            {
                nums.erase(nums.begin() + i);
            }
        }
        return result;
    }
};