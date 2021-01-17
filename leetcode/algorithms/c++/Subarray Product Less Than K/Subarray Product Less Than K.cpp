class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        int r = 0;
        int il = 1;
        int begin = 0;
        int end = 0;
        for (auto &x : nums)
        {

            il *= nums[end++];
            while (begin < end && il >= k)
            {
                il /= nums[begin];
                ++begin;
            }
            r += end - begin;
        }
        return r;
    }
};