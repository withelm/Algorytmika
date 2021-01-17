class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        vector<long long int> nums;
        for (long long int i = 0; i * i <= c; i++)
        {
            nums.push_back(i * i);
        }
        for (auto &x : nums)
        {
            if (binary_search(nums.begin(), nums.end(), c - x))
            {
                return true;
            }
        }
        return false;
    }
};