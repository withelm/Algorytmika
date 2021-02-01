class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> r;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                if (((i & (1 << j)) == (1 << j)))
                    tmp.push_back(nums[j]);
            }
            r.push_back(tmp);
        }
        return r;
    }
};