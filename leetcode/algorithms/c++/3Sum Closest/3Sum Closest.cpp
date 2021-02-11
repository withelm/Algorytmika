class Solution
{
private:
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 2 * 1e9;
        for (int i = 0; i < n; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(res))
                    res = target - sum;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return target - res;
    }
};