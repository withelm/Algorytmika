class Solution
{
private:
    map<int, int> db;

public:
    int maximumUniqueSubarray(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;

        int result = nums[0];
        int begin = 0;
        int end = 1;
        ++db[nums[0]];
        int sum = nums[0];
        int n = nums.size();

        while (begin < n && end < n)
        {

            while (db[nums[end]] > 0)
            {
                --db[nums[begin]];
                sum -= nums[begin];
                ++begin;
            }
            ++db[nums[end]];
            sum += nums[end];
            result = max(result, sum);
            ++end;
        }

        return result;
    }
};