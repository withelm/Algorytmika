class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        map<int, vector<int>> base;
        int n = nums.size();
        int tmp_r = 0;
        for (int i = 0; i < n; i++)
        {
            base[nums[i]].push_back(i);
            tmp_r = max(tmp_r, (int)base[nums[i]].size());
        }
        int r = n;
        for (auto &x : base)
        {
            if (x.second.size() == tmp_r)
            {
                r = min(r, x.second[tmp_r - 1] - x.second[0] + 1);
            }
        }
        return r;
    }
};