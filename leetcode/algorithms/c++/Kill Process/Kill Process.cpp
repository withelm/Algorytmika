class Solution
{
private:
    map<int, vector<int>> g;
    int n;
    vector<int> r;

    void dfs(int x)
    {
        r.push_back(x);
        for (auto &i : g[x])
            dfs(i);
    }

public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        n = pid.size();

        for (int i = 0; i < n; i++)
        {
            g[ppid[i]].push_back(pid[i]);
        }

        dfs(kill);

        return r;
    }
};