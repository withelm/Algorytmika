class Solution
{
private:
    bool check(int x, int y, vector<vector<int>> &grid)
    {
        int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        for (int i = 0; i < 3; i++)
        {
            int sum_tmp = 0;
            for (int j = 0; j < 3; j++)
            {
                sum_tmp += grid[x + i][y + j];
            }
            if (sum != sum_tmp)
                return false;
        }
        for (int i = 0; i < 3; i++)
        {
            int sum_tmp = 0;
            for (int j = 0; j < 3; j++)
            {
                sum_tmp += grid[x + j][y + i];
            }
            if (sum != sum_tmp)
                return false;
        }
        int sum_x = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int sum_y = grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2];
        if (!(sum == sum_x && sum_x == sum_y))
            return false;
        set<int> k;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[x + i][y + j] > 9 || grid[x + i][y + j] <= 0)
                    return false;
                k.insert(grid[x + i][y + j]);
            }
        }
        return k.size() == 9;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                result += check(i, j, grid);
            }
        }
        return result;
    }
};