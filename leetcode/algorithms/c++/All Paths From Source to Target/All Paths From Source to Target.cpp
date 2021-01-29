class Solution
{
private:
    vector<vector<int>> r;
    int n;
    void dfs(vector<vector<int>> &g, int k, vector<int> &tmp)
    {
        if (n - 1 == k)
        {
            r.push_back(tmp);
            return;
        }
        for (auto &x : g[k])
        {
            tmp.push_back(x);
            dfs(g, x, tmp);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size();
        vector<int> tmp = {0};
        dfs(graph, 0, tmp);
        return r;
    }
};