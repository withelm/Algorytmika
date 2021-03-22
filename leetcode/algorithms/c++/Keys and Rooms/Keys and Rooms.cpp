class Solution
{
private:
    vector<vector<int>> g;
    vector<bool> vis;
    int n;

    void dfs(int x)
    {
        if (vis[x])
            return;
        vis[x] = true;
        for (auto &i : g[x])
            dfs(i);
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        n = rooms.size();
        g = rooms;
        vis.resize(n, false);
        dfs(0);
        for (auto x : vis)
            if (!x)
                return false;
        return true;
    }
};