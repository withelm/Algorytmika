class Solution
{
private:
    vector<vector<int>> dp;
    string s;
    int n;

    int check(int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        return dp[x][y] = (s[x] == s[y] && check(x + 1, y - 1));
    }

    void init()
    {
        dp.resize(n);
        for (int i = 0; i < n; i++)
            dp[i].resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == s[i])
            {
                dp[i - 1][i] = 1;
                dp[i][i - 1] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (dp[i][j] == -1)
                    dp[i][j] = check(i, j);
            }
        }
    }

public:
    bool checkPartitioning(string word)
    {
        s = word;
        n = s.size();
        init();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i + 1 <= j - 1 && dp[0][i] == 1 && dp[i + 1][j - 1] == 1 && dp[j][n - 1] == 1)
                    return true;
            }
        }
        return false;
    }
};