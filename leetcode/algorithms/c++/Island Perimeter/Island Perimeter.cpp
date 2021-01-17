class Solution
{
private:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

    int calc(vector<vector<int>> &g, int x, int y)
    {
        int r = 0;
        for (auto &i : moves)
        {
            int offX = x + i[0];
            int offY = y + i[1];

            if (offX < 0 || offX >= n || offY < 0 || offY >= m)
            {
                ++r;
            }
            else
            {
                r += g[offX][offY] == 0;
            }
        }
        return r;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int r = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                {
                    r += calc(grid, i, j);
                }
            }
        }
        return r;
    }
};