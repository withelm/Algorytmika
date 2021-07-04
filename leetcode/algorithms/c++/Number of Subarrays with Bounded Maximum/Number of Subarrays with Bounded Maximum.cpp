class Solution
{
private:
    int calc(vector<int> &nums, int val)
    {
        int res = 0;
        int cnt = 0;
        for (auto &x : nums)
        {
            if (x <= val)
                ++cnt;
            else
                cnt = 0;
            res += cnt;
        }
        return res;
    }

public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        return calc(nums, right) - calc(nums, left - 1);
    }
};