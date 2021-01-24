class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<vector<int>, int> base;
        for (auto &x : dominoes)
        {
            if (x[0] > x[1])
                ++base[{x[1], x[0]}];
            else
                ++base[x];
        }
        int r = 0;
        for (auto &x : base)
        {
            r += ((x.second) * (x.second - 1)) / 2;
        }
        return r;
    }
};