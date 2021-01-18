class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int r = 0;
        sort(nums.begin(), nums.end());
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end)
        {
            if (nums[begin] + nums[end] > k)
            {
                --end;
            }
            else if (nums[begin] + nums[end] < k)
            {
                ++begin;
            }
            else
            {
                ++r;
                ++begin;
                --end;
            }
        }
        return r;
    }
};