class Solution
{
private:
    vector<vector<int>> g;
    vector<int> d;
    vector<vector<int>> r;

    int dfs(int last, int curr, int depth)
    {
        d[curr] = depth;
        int min_depth = depth;

        for (auto &item : g[curr])
        {
            if (item == last)
                continue;
            int tmp = d[item];
            if (tmp == -1)
                tmp = dfs(curr, item, depth + 1);
            if (tmp > depth)
                r.push_back({curr, item});
            else
                min_depth = min(min_depth, tmp);
        }
        return d[curr] = min_depth;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        g.resize(n);
        for (auto &x : connections)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        d.resize(n);
        for (auto &x : d)
            x = -1;
        dfs(-1, 0, 0);
        return r;
    }
};