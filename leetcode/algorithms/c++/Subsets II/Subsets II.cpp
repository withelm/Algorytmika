class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> r;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                if (((i & (1 << j)) == (1 << j)))
                    tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());
            r.insert(tmp);
        }

        vector<vector<int>> result;
        for (auto &x : r)
            result.push_back(x);

        return result;
    }
};