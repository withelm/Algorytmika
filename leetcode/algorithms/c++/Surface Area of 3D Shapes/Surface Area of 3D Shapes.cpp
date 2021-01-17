class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int r = 0;

        for (int i = 0; i < n; i++)
        {
            grid[i].push_back(0);
            r += grid[i][0];
            r += grid[n - 1][i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    r += 2;

                r += abs(grid[i][j] - grid[i][j + 1]);
                if (i - 1 < 0)
                    r += grid[i][j];
                else
                    r += abs(grid[i][j] - grid[i - 1][j]);
            }
        }
        return r;
    }
};