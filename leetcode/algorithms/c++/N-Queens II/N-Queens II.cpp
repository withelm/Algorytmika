class Solution
{
private:
    int r = 0;

    bool check(vector<vector<int>> &t, int x, int y, int n)
    {
        return t[x][y] == 0;
    }

    void update(vector<vector<int>> &t, int x, int y, int n, int val)
    {

        for (int i = 0; i < n; i++)
        {
            t[x][i] += val;
            t[i][y] += val;
        }
        int index = 0;
        while (x + index < n && y - index >= 0)
        {
            t[x + index][y - index] += val;
            ++index;
        }
        index = 0;
        while (x + index < n && y + index < n)
        {
            t[x + index][y + index] += val;
            ++index;
        }
    }

    void dfs(vector<vector<int>> &t, int n, int limit, int i, int j)
    {

        if (limit == 0)
        {
            ++r;
            return;
        }
        for (int x = i; x < n; x++)
        {
            for (int y = (x == i) ? j : 0; y < n; y++)
            {
                if (check(t, x, y, n))
                {

                    update(t, x, y, n, 1);

                    dfs(t, n, limit - 1, x, y);
                    update(t, x, y, n, -1);
                }
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<vector<int>> t(n, vector<int>(n, 0));
        dfs(t, n, n, 0, 0);
        return r;
    }
};