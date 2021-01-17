class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        vector<vector<long long int>> base;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            base.push_back({nums[i], i});
        }
        sort(base.begin(), base.end());
        int index_1 = 0;
        int index_2 = 1;
        while (index_2 < n)
        {
            if (abs(base[index_1][0] - base[index_2][0]) <= t && abs(base[index_1][1] - base[index_2][1]) <= k)
                return true;

            ++index_2;
            while (index_1 < n && index_2 < n && abs(base[index_1][0] - base[index_2][0]) > t)
                ++index_1;
            if (index_1 >= index_2)
                index_2 = index_1 + 1;
        }
        return false;
    }
};