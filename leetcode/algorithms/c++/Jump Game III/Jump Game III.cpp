class Solution
{
private:
    vector<bool> vis;
    vector<int> _arr;
    int n;

    void dfs(int x)
    {
        if (x < 0 || x >= n)
            return;
        if (vis[x])
            return;
        vis[x] = true;
        dfs(x - _arr[x]);
        dfs(x + _arr[x]);
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        _arr = arr;
        n = arr.size();
        vis.resize(n);
        for (int i = 0; i < n; i++)
            vis[i] = false;

        dfs(start);
        for (int i = 0; i < n; i++)
            if (arr[i] == 0 && vis[i])
                return true;
        return false;
    }
};