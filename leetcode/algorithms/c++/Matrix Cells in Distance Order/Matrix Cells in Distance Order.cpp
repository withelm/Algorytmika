class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> r;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                r.push_back({i - r0, j - c0});
            }
        }

        sort(r.begin(), r.end(),
             [](const vector<int> &a, const vector<int> &b) -> bool {
                 return abs(a[0]) + abs(a[1]) < abs(b[0]) + abs(b[1]);
             });

        for (auto &x : r)
        {
            x[0] += r0;
            x[1] += c0;
        }

        return r;
    }
};