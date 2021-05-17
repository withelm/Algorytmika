class Solution
{
private:
    int MX = 300;
    int INF = 1e9;
    map<int, map<int, int>> dp;

    vector<vector<int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {2, -1}};

public:
    int minKnightMoves(int x, int y)
    {
        MX = max(abs(x), abs(y)) + 2;
        for (int i = -3; i <= MX; i++)
        {
            for (int j = -3; j <= MX; j++)
            {
                dp[i][j] = INF;
            }
        }

        dp[0][0] = 0;
        vector<vector<int>> qu = {{0, 0}};

        int deep = 1;
        while (!qu.empty())
        {
            vector<vector<int>> next;
            for (auto &item : qu)
            {
                for (auto &move : moves)
                {
                    int xx = item[0] + move[0];
                    int yy = item[1] + move[1];

                    if (xx < -3 || yy < -3 || xx >= MX || yy >= MX)
                        continue;
                    if (dp[xx][yy] == INF)
                    {
                        dp[xx][yy] = deep;
                        next.push_back({xx, yy});
                    }
                }
            }
            ++deep;
            qu = next;
        }
        return dp[abs(x)][abs(y)];
    }
};