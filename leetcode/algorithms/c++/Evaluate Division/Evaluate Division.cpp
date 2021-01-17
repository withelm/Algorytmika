class Solution
{
private:
    map<string, int> con;
    vector<string> revCon;
    vector<bool> vis;
    double rr;
    vector<vector<pair<int, double>>> graph;
    double dfs(int from, int to, double val)
    {

        if (vis[from])
            return val;
        vis[from] = true;
        if (from == to)
        {
            rr = val;
            return val;
        }
        for (auto &x : graph[from])
        {
            dfs(x.first, to, val * x.second);
        }
        return val;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int index = 0;
        for (auto &x : equations)
        {
            for (auto &i : x)
            {
                if (con.find(i) == con.end())
                {
                    con[i] = index;
                    revCon.push_back(i);
                    ++index;
                }
            }
        }
        graph.resize(index);
        vis.resize(index, false);
        for (int i = 0; i < equations.size(); i++)
        {
            auto from = equations[i][0];
            auto to = equations[i][1];
            graph[con[from]].push_back({con[to], values[i]});
            graph[con[to]].push_back({con[from], 1 / values[i]});
        }

        vector<double> r;
        for (auto &x : queries)
        {
            auto from = x[0];
            auto to = x[1];
            if (con.find(from) == con.end())
            {
                r.push_back(-1);
                continue;
            }
            if (con.find(to) == con.end())
            {
                r.push_back(-1);
                continue;
            }
            if (from == to)
            {
                r.push_back(1);
                continue;
            }
            auto from_id = con[from];
            auto to_id = con[to];
            for (int i = 0; i < index; i++)
                vis[i] = false;
            rr = -1;
            dfs(from_id, to_id, 1);
            r.push_back(rr);
        }
        return r;
    }
};