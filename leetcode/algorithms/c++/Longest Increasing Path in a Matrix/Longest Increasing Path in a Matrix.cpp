class Solution
{
private:
    vector<vector<int>> t;

    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> dp;
    int n, m;

    map<int, vector<vector<int>>> order;

    void init(vector<vector<int>> &matrix)
    {
        t = matrix;
        n = t.size();
        if (n == 0)
            return;
        m = t[0].size();

        dp.resize(n);
        for (int i = 0; i < n; i++)
        {

            dp[i].resize(m);
            for (int j = 0; j < m; j++)
            {

                dp[i][j] = 1;
                order[-t[i][j]].push_back({i, j});
            }
        }
    }

    bool check(vector<int> &x, vector<int> &y)
    {
        int _x = x[0] + y[0];
        int _y = x[1] + y[1];
        return !(_x < 0 || _x >= n || _y < 0 || _y >= m);
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        init(matrix);
        int r = 0;

        for (auto &row : order)
        {
            for (auto &cord : row.second)
            {
                for (auto &move : moves)
                {

                    if (check(cord, move))
                    {
                        int x = cord[0] + move[0];
                        int y = cord[1] + move[1];
                        if (t[x][y] < t[cord[0]][cord[1]])
                            dp[x][y] = max(dp[x][y], dp[cord[0]][cord[1]] + 1);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                r = max(r, dp[i][j]);

        return r;
    }
};