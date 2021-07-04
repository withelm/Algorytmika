class Solution
{

private:
    int MOD = 1e9 + 7;
    map<vector<int>, int> dp;

    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (startRow == m || startColumn == n || startRow < 0 || startColumn < 0)
            return 1;
        if (maxMove == 0)
            return 0;
        auto key = {startRow, startColumn, maxMove};
        if (dp.find(key) != dp.end())
            return dp[key];
        int res = 0;
        for (auto &move : moves)
        {
            res = (res + dfs(m, n, maxMove - 1, startRow + move[0], startColumn + move[1])) % MOD;
        }

        return dp[key] = res;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        return dfs(m, n, maxMove, startRow, startColumn);
    }
};