class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> base;
        for (auto &x : nums)
            ++base[x];

        int r = 0;
        for (auto &x : base)
        {

            if (base.find(x.first - 1) != base.end())
                r = max(r, x.second + base[x.first - 1]);
            if (base.find(x.first + 1) != base.end())
                r = max(r, x.second + base[x.first + 1]);
        }
        return r;
    }
};