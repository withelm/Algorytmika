class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = 0;

        vector<int> prefix;
        int sum = 0;
        prefix.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix.push_back(sum);
        }

        result = sum;
        for (int i = 0; i < nums.size(); i++)
        {
            if (result < nums[i])
                result = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = prefix[j + 1] - prefix[i];
                if (sum > result)
                    result = sum;
            }
        }

        return result;
    }
};