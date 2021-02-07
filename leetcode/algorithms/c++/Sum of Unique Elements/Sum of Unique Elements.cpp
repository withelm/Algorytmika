class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        map<int, int> base;
        int r = 0;
        for (auto &x : nums)
            base[x]++;
        for (auto &x : base)
            if (x.second == 1)
                r += x.first;
        return r;
    }
};