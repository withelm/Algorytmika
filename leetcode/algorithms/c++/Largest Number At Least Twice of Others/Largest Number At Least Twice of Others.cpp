class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0;
        int v = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (v < nums[i])
            {
                index = i;
                v = nums[i];
            }
        }
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;

        sort(nums.begin(), nums.end());
        if (nums[n - 1] < nums[n - 2] * 2)
            return -1;
        return index;
    }
};