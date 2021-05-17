class Solution
{
private:
    vector<bool> vis;
    vector<vector<int>> g;

    void dfs(int x)
    {
        if (vis[x])
            return;
        vis[x] = true;
        for (auto i : g[x])
        {
            if (!vis[i])
                dfs(i);
        }
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vis.resize(n);
        g.resize(n);
        for (auto x : vis)
            x = false;

        for (auto &item : edges)
        {
            g[item[0]].push_back(item[1]);
            g[item[1]].push_back(item[0]);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                ++result;
            }
        }
        return result;
    }
};