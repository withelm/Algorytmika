class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        int n = nums.size();
        if (n == 0)
            return result;

        int begin = nums[0];
        int end = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (end + 1 == nums[i])
            {
                end = nums[i];
                continue;
            }
            else
            {
                string tmp;
                if (begin != end)
                    tmp = to_string(begin) + "->" + to_string(end);
                else
                    tmp = to_string(begin);
                begin = nums[i];
                end = nums[i];
                result.push_back(tmp);
            }
        }
        string tmp;
        if (begin != end)
            tmp = to_string(begin) + "->" + to_string(end);
        else
            tmp = to_string(begin);
        result.push_back(tmp);
        return result;
    }
};