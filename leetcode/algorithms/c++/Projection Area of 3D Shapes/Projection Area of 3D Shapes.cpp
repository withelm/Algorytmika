class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int result = 0;
        int n, m;
        n = grid.size();
        m = grid[0].size();

        result += n * m;
        for (int i = 0; i < n; i++)
        {
            int max_row = grid[i][0];
            for (int j = 0; j < m; j++)
            {
                max_row = max(max_row, grid[i][j]);
                if (grid[i][j] == 0)
                    --result;
            }
            result += max_row;
        }
        for (int i = 0; i < n; i++)
        {
            int max_row = grid[0][i];
            for (int j = 0; j < m; j++)
            {
                max_row = max(max_row, grid[j][i]);
            }
            result += max_row;
        }
        return result;
    }
};