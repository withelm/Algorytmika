class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int sum_tmp = 0;
        for (auto &x : nums)
            sum_tmp += x;
        return sum - sum_tmp;
    }
};