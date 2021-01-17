class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> p(n, nums[0]);
        for (int i = 1; i < n; i++)
        {
            p[i] = min(p[i - 1], nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i] && p[i] < nums[j])
                    return true;
            }
        }
        return false;
    }
};