class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> column(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                row[i] = max(row[i], grid[i][j]);
                column[j] = max(column[j], grid[i][j]);
            }
        }
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                r += min(row[i], column[j]) - grid[i][j];
            }
        }
        return r;
    }
};