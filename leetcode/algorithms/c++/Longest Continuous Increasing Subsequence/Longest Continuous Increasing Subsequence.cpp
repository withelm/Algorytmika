class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int r = 1;
        int tmp_r = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ++tmp_r;
            }
            else
            {
                r = max(r, tmp_r);
                tmp_r = 1;
            }
        }
        return max(r, tmp_r);
    }
};