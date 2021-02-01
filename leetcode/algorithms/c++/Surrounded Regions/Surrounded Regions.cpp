class Solution
{
private:
    vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int n, m;
    void dfs(vector<vector<char>> &t, int x, int y, char val, char source)
    {
        if (x < 0 || y < 0 || x >= t.size() || y >= t[0].size())
            return;
        if (t[x][y] == source)
        {
            t[x][y] = val;
            for (auto &move : moves)
                dfs(t, x + move[0], y + move[1], val, source);
        }
    }

    void init(vector<vector<char>> &board, char from, char to)
    {
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == from)
                dfs(board, i, 0, to, from);
            if (board[i][m - 1] == from)
                dfs(board, i, m - 1, to, from);
        }
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == from)
                dfs(board, 0, i, to, from);
            if (board[n - 1][i] == from)
                dfs(board, n - 1, i, to, from);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {

        n = board.size();
        if (n == 0)
            return;
        m = board[0].size();
        init(board, 'O', 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    dfs(board, i, j, 'X', 'O');
            }
        }

        init(board, 0, 'O');
    }
};