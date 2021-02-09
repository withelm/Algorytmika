class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> base;
        for (auto &x : nums)
        {
            if (base.find(x) != base.end())
                return x;
            base.insert(x);
        }
        return -1;
    }
};