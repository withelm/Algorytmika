class Solution
{
public:
    int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int>> &nuts)
    {
        int maxLen = 0;
        for (auto &x : nuts)
        {
            maxLen += abs(x[0] - tree[0]) + abs(x[1] - tree[1]);
        }
        maxLen *= 2;
        int r = 1e9 + 1e9;

        for (auto &x : nuts)
        {
            r = min(r, maxLen - abs(x[0] - tree[0]) - abs(x[1] - tree[1]) + abs(squirrel[0] - x[0]) + abs(squirrel[1] - x[1]));
        }
        return r;
    }
};