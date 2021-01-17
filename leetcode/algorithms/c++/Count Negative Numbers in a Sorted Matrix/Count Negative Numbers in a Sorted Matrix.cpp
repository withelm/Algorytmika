class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int r = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                r += grid[i][j] < 0 ? 1 : 0;
            }
        }
        return r;
    }
};