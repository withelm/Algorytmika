class Solution
{
private:
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> s;
    vector<int> start;
    unordered_set<int> list;
    int INF = 1e9;

    void init(vector<vector<int>> &t, int n)
    {
        g.resize(n + 1);
        s.resize(n + 1);
        for (auto &x : t)
        {
            g[x[0]].push_back(x[1]);
            ++s[x[0]];
            g[x[1]].push_back(x[0]);
            ++s[x[1]];
            list.insert(x[0]);
            list.insert(x[1]);
        }
        vis.resize(n + 1, INF);
    }

    void remove()
    {
        for (auto &x : start)
        {
            for (auto &i : g[x])
            {
                --s[i];
            }
            s[x] = -INF;
            list.erase(x);
        }
        start.clear();
    }
    void find(int deep, int n)
    {
        for (auto i : list)
        {
            if (s[i] == 1)
            {
                vis[i] = deep;
                start.push_back(i);
            }
        }
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        init(edges, n);
        int s = 0;
        find(s++, n);
        while (start.size() != 0)
        {

            remove();

            find(s++, n);
        }

        for (int i = 0; i < n; i++)
            if (vis[i] == INF)
                return {i};

        vector<int> r;

        for (int i = 0; i <= n; i++)
        {

            if (vis[i] == s - 2)
                r.push_back(i);
        }

        return r;
    }
};