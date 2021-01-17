class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> tmp(m, vector<int>(n, 0));

        while (k--)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == m - 1 && j == n - 1)
                    {
                        tmp[0][0] = grid[i][j];
                    }
                    else if (j == n - 1)
                    {
                        tmp[(i + 1)][0] = grid[i][j];
                    }
                    else
                    {
                        tmp[i][(j + 1)] = grid[i][j];
                    }
                }
            }
            grid = tmp;
        }
        return grid;
    }
};