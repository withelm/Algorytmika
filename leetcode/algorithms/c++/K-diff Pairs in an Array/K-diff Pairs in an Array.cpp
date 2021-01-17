class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        if (k > 0)
        {
            set<vector<int>> v;
            sort(nums.begin(), nums.end());
            for (auto &x : nums)
            {
                if (binary_search(nums.begin(), nums.end(), x + k))
                {
                    v.insert({x, x + k});
                }
            }
            return v.size();
        }
        else
        {
            map<int, int> c;
            for (auto &x : nums)
            {
                ++c[x];
            }
            int result = 0;
            for (auto &x : c)
            {
                if (x.second > 1)
                    ++result;
            }
            return result;
        }
        return -1;
    }
};