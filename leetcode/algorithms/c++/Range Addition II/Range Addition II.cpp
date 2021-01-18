class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.size() == 0)
            return m * n;
        int x = 1e9;
        int y = 1e9;

        for (auto &i : ops)
        {
            x = min(i[0], x);
            y = min(i[1], y);
        }
        return x * y;
    }
};