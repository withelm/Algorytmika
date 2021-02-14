class Solution
{
private:
    map<int, int> color;
    vector<vector<int>> g;
    int n;
    map<int, int> findG;

    int find(int x)
    {
        if (findG[x] == x)
            return x;
        return findG[x] = find(findG[x]);
    }

    void unionF(int x, int y)
    {
        findG[find(x)] = findG[find(y)];
    }

    bool bfs(vector<int> t, int col)
    {
        vector<int> next;
        if (t.size() == 0)
            return true;
        for (auto &i : t)
        {
            for (auto &j : g[i])
            {

                if (color[j] == -1)
                {
                    color[j] = col;
                    next.push_back(j);
                }
                else
                {
                    if (color[j] != col)
                        return false;
                }
            }
        }
        return bfs(next, (col + 1) % 2);
    }

    void init()
    {
        for (int i = 0; i < n; i++)
            color[i] = -1;
    }
    bool isBipartiteSmall(int findGroup)
    {

        for (int i = 0; i < n; i++)
        {
            if (find(i) == findGroup)
            {
                init();
                color[i] = 0;

                if (bfs({i}, 1))
                    return true;
            }
        }
        return false;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        g = graph;
        for (int i = 0; i < n; i++)
            findG[i] = i;
        for (int j = 0; j < n; j++)
        {
            auto x = graph[j];
            for (auto &i : x)
            {
                unionF(j, i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!isBipartiteSmall(find(i)))
                return false;
        }
        return true;
    }
};