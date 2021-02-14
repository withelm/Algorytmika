class Solution
{
private:
    vector<vector<int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n;
    bool isEnd = false;
    void bfs(vector<vector<int>> que, vector<vector<int>> &grid, int deep)
    {
        vector<vector<int>> t;
        if (que.size() == 0)
            return;

        for (auto &x : que)
        {
            if (x[0] < 0 || x[0] >= n || x[1] < 0 || x[1] >= n)
                continue;
            if (grid[x[0]][x[1]] != 0)
                continue;
            grid[x[0]][x[1]] = deep;
            if (x[0] == n - 1 && x[1] == n - 1)
                isEnd = true;
            for (auto &move : moves)
                t.push_back({x[0] + move[0], x[1] + move[1]});
        }
        bfs(t, grid, deep + 1);
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        n = grid.size();
        bfs({{0, 0}}, grid, 2);
        return isEnd ? grid.back().back() - 1 : -1;
    }
};