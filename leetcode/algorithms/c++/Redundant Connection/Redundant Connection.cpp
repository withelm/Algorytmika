class Solution
{
private:
    int MX = 1000 + 10;
    vector<int> t;

    int find(int x)
    {
        if (t[x] != x)
            return t[x] = find(t[x]);
        return x;
    }

    void unionAll(int x, int y)
    {
        t[find(x)] = t[find(y)];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        t.resize(MX);

        for (int i = 0; i < MX; i++)
        {
            t[i] = i;
        }

        for (auto &edge : edges)
        {
            if (find(edge[0]) == find(edge[1]))
                return edge;
            unionAll(edge[0], edge[1]);
        }
        return {-1, -1};
    }
};