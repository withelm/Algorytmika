class Solution
{
private:
    vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    vector<vector<char>> t_grid;

    bool check(vector<int> &move, int x, int y)
    {
        if (move[0] + x < 0 || move[0] + x >= n)
            return false;
        if (move[1] + y < 0 || move[1] + y >= m)
            return false;
        return true;
    }
    vector<vector<bool>> vis;

    bool findCycle(int x, int y, char c)
    {
        return dfs(x, y, x, y);
    }

    bool dfs(int x, int y, int old_x, int old_y)
    {

        if (vis[x][y])
            return true;
        vis[x][y] = true;

        for (auto &mo : moves)
        {

            int nw_x = x + mo[0];
            int nw_y = y + mo[1];

            if (check(mo, x, y))
            {
                if (nw_x == old_x && nw_y == old_y)
                    continue;

                if (t_grid[x][y] == t_grid[nw_x][nw_y])
                {
                    if (dfs(nw_x, nw_y, x, y))
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return false;
        t_grid = grid;
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis2(n);
        for (int i = 0; i < n; i++)
        {
            vector<bool> tmp(m);
            for (int j = 0; j < m; j++)
            {
                tmp[j] = false;
            }
            vis2[i] = tmp;
        }
        vis = vis2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    if (findCycle(i, j, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};