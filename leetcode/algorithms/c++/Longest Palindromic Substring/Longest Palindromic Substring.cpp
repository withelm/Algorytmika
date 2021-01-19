class Solution
{
private:
    int n;
    string str;
    vector<vector<int>> dp;
    vector<vector<bool>> vis;

    int dfs(int x, int y)
    {
        if (x < 0 || y < 0 || x >= n || y >= n || x > y)
            return 0;

        if (vis[x][y])
            return dp[x][y];
        vis[x][y] = true;

        if (str[x] == str[y])
        {

            int ans = dfs(x + 1, y - 1);
            return dp[x][y] = ans > 0 ? ans + 2 : 0;
        }
        return 0;
    }

public:
    string longestPalindrome(string s)
    {
        n = s.size();
        if (n == 0)
            return "";

        str = s;
        dp.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(n);
            vis[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = 0;
                vis[i][j] = false;
            }
        }

        int len = -1;
        int x = -1;
        int y = -1;

        for (int i = 0; i < n; i++)
        {
            vis[i][i] = true;
            dp[i][i] = true;
            if (i + 1 < n && s[i] == s[i + 1])
            {
                vis[i][i + 1] = true;
                dp[i][i + 1] = 2;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = dfs(i, j);
                if (dp[i][j] > len)
                {
                    x = i;
                    y = j;
                    len = dp[i][j];
                }
            }
        }

        string res = "";
        for (int i = x; i <= y; i++)
            res += str[i];

        return res;
    }
};