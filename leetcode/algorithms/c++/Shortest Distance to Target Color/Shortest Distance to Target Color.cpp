class Solution
{
private:
    int INF = 1e9;

public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries)
    {
        int n = colors.size();
        vector<vector<int>> mem(4, vector<int>(n, INF));

        vector<int> last(4, INF);
        for (int i = 0; i < n; i++)
        {
            last[colors[i]] = i;
            for (int j = 1; j < 4; j++)
            {
                mem[j][i] = last[j] != INF ? abs(i - last[j]) : INF;
            }
        }
        last = {INF, INF, INF, INF};
        for (int i = n - 1; i >= 0; i--)
        {
            last[colors[i]] = i;
            for (int j = 1; j < 4; j++)
            {
                mem[j][i] = min(mem[j][i], last[j] != INF ? abs(i - last[j]) : INF);
            }
        }
        vector<int> r;
        for (auto &query : queries)
            r.push_back(mem[query[1]][query[0]] == INF ? -1 : mem[query[1]][query[0]]);
        return r;
    }
};