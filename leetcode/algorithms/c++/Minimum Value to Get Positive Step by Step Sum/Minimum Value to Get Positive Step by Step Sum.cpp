class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;

        int minimum = nums[0];
        int sum = minimum;
        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            minimum = min(minimum, sum);
        }
        return max(1, -minimum + 1);
    }
};