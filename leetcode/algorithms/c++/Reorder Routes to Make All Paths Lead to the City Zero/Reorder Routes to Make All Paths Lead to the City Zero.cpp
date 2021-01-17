class Solution
{
private:
    int MX = 5 * 10e4 + 10;
    vector<vector<int>> graphA, graphB;
    int result = 0;
    void dfs(int acc, int old)
    {
        for (auto &x : graphB[acc])
        {
            if (old != x)
            {
                dfs(x, acc);
            }
        }
        for (auto &x : graphA[acc])
        {
            if (old != x)
            {
                ++result;
                dfs(x, acc);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        graphA.resize(n);
        graphB.resize(n);
        for (auto &row : connections)
        {
            graphA[row[0]].push_back(row[1]);
            graphB[row[1]].push_back(row[0]);
        }

        dfs(0, -1);

        return result;
    }
};