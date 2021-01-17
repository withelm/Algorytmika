class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] + nums[i];

        int max_sum = p[k - 1];
        for (int i = 0; i < n - k; i++)
        {
            max_sum = max(max_sum, p[i + k] - p[i]);
        }

        return (double)max_sum / (double)k;
    }
};