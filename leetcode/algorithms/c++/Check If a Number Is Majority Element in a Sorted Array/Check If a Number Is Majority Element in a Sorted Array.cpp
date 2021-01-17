class Solution
{
public:
    bool isMajorityElement(vector<int> &nums, int target)
    {
        map<int, int> base;
        for (auto &x : nums)
            ++base[x];
        int n = nums.size();

        return base[target] > n / 2;
    }
};