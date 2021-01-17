class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, vector<int>> base;
        int index = 0;
        for (auto &x : nums)
            base[x].push_back(index++);
        for (auto &x : base)
        {
            int n = x.second.size();
            if (n == 1)
                continue;
            for (int i = 1; i < n; i++)
            {
                if (x.second[i] - x.second[i - 1] <= k)
                    return true;
            }
        }
        return false;
    }
};