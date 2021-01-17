class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int r = 0;
        for (auto &i : accounts)
        {
            int s = 0;
            for (auto &j : i)
                s += j;
            r = max(r, s);
        }
        return r;
    }
};