class Solution
{
private:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return 0;
        if (grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        int r = 1;
        for (auto &move : moves)
            r += dfs(move[0] + x, move[1] + y, grid);
        return r;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    result = max(result, dfs(i, j, grid));
                }
            }
        }
        return result;
    }
};