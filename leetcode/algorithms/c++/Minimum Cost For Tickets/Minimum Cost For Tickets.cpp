class Solution
{
private:
    vector<int> v;
    vector<int> c;
    set<int> d;
    int dfs(int x)
    {
        if (x > 370)
            return 0;
        if (v[x] != 0)
            return v[x];
        if (d.find(x) != d.end())
        {
            v[x] = min(dfs(x + 1) + c[0], dfs(x + 7) + c[1]);
            v[x] = min(v[x], dfs(x + 30) + c[2]);
        }
        else
        {
            v[x] = dfs(x + 1);
        }
        return v[x];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        v = vector<int>(400, 0);
        for (auto &x : days)
        {
            d.insert(x);
        }
        c = costs;
        if (days.size() == 0)
            return 0;

        sort(days.begin(), days.end());
        int n = days.size();

        return dfs(1);
    }
};