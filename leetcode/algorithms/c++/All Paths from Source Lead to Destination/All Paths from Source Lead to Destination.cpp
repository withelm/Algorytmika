class Solution
{
private:
    vector<vector<int>> g;
    vector<int> vis;
    int n;

    bool dfs(int v, int p)
    {
        if (g[v].empty())
            return v == p;
        if (vis[v] != -1)
            return vis[v];
        vis[v] = 0;
        for (auto &item : g[v])
            if (!dfs(item, p))
                return false;
        return vis[v] = true;
    }

public:
    bool leadsToDestination(int _n, vector<vector<int>> &edges, int source, int destination)
    {
        n = _n;
        g.resize(n);
        for (auto &edge : edges)
            g[edge[0]].push_back(edge[1]);

        vector<int> q = {source};
        vis.resize(n);
        for (int i = 0; i < n; i++)
            vis[i] = -1;

        return dfs(source, destination);
    }
};