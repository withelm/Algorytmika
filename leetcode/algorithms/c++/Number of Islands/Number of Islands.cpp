class Solution
{
private:
    vector<vector<char>> t;
    int n, m;
    void dfs(int x, int y, char old, char newc)
    {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return;
        if (t[x][y] != old)
            return;

        t[x][y] = newc;
        dfs(x + 1, y, old, newc);
        dfs(x - 1, y, old, newc);
        dfs(x, y + 1, old, newc);
        dfs(x, y - 1, old, newc);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        t = grid;

        n = grid.size();
        m = grid[0].size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] == '1')
                {
                    dfs(i, j, '1', '0');
                    ++r;
                }
            }
        }

        return r;
    }
};