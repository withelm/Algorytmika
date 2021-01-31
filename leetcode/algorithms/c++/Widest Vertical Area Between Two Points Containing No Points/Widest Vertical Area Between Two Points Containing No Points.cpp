class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        set<int> base;
        for (auto &i : points)
        {
            base.insert(i[0]);
        }
        vector<int> r;
        for (auto &x : base)
            r.push_back(x);
        int res = 0;
        for (int i = 1; i < r.size(); i++)
            res = max(res, r[i] - r[i - 1]);
        return res;
    }
};