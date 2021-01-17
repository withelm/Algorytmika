class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> base;
        int n = nums.size();
        for (auto &x : nums)
            base[x]++;
        vector<int> result;
        for (auto &x : base)
        {
            if (x.second > n / 3)
                result.push_back(x.first);
        }
        return result;
    }
};