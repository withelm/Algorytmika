class Solution
{
private:
    vector<vector<int>> dp;
    int n1, n2, n3;
    string s1, s2, s3;

    bool check(int j, string s2, int k)
    {
        for (int index = j; index < s2.size(); index++)
        {
            if (s2[index] != s3[k++])
                return false;
        }
        return true;
    }

    bool dfs(int i, int j, int k)
    {
        if (i == n1)
        {
            return check(j, s2, k);
        }
        if (j == n2)
        {
            return check(i, s1, k);
        }
        if (dp[i][j] > -1)
            return dp[i][j] == 1;

        if (s3[k] == s1[i] && dfs(i + 1, j, k + 1))
        {
            dp[i][j] = 1;
        }
        else if (s3[k] == s2[j] && dfs(i, j + 1, k + 1))
        {
            dp[i][j] = 1;
        }
        else
        {
            dp[i][j] = 0;
        }
        return dp[i][j] == 1;
    }

public:
    bool isInterleave(string _s1, string _s2, string _s3)
    {
        s1 = _s1;
        s2 = _s2;
        s3 = _s3;
        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();

        if (n1 + n2 != n3)
            return false;
        dp.resize(n1);
        for (auto &row : dp)
        {
            row.resize(n2);
            for (auto &cell : row)
                cell = -1;
        }
        return dfs(0, 0, 0);
    }
};