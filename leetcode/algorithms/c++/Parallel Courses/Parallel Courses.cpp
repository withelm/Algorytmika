class Solution
{
private:
    vector<vector<int>> g;
    vector<int> kub;
    vector<int> vis;

public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        g.resize(n + 1);
        kub.resize(n + 1);
        vis.resize(n + 1, false);
        for (auto &item : relations)
        {
            g[item[0]].push_back(item[1]);
            ++kub[item[1]];
        }
        int r = 0;
        vector<int> next;
        do
        {
            next.clear();
            for (int i = 1; i <= n; i++)
            {
                if (kub[i] == 0 && vis[i] == false)
                {
                    next.push_back(i);
                    vis[i] = true;
                }
            }
            for (auto &x : next)
            {
                for (auto &i : g[x])
                    --kub[i];
            }

            ++r;
        } while (next.size() > 0);
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                return -1;
        return r - 1;
    }
};