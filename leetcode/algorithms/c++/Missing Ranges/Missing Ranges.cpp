class Solution
{
private:
    string toStr(int lower, int upper)
    {
        if (lower == upper)
            return to_string(lower);
        else
            return to_string(lower) + "->" + to_string(upper);
    }

public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        int index = 0;
        int n = nums.size();
        vector<string> r;

        if (n == 0)
        {
            return {toStr(lower, upper)};
        }

        if (lower < nums[0])
            r.push_back(toStr(lower, nums[0] - 1));
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] > 1)
            {
                r.push_back(toStr(nums[i - 1] + 1, nums[i] - 1));
            }
        }
        if (upper > nums[n - 1])
            r.push_back(toStr(nums[n - 1] + 1, upper));

        return r;
    }
};