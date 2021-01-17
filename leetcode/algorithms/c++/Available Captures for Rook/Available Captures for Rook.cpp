class Solution
{
private:
    vector<vector<int>> m = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> b;
    int n = 8;
    int x, y;
    int check(vector<int> move, int i, int j)
    {
        //cout << i << " " << j << endl;
        if (i < 0 || j < 0 || i >= n || j >= n)
            return 0;
        if (b[i][j] == 'p')
            return 1;
        if (b[i][j] == '.')
            return check(move, i + move[0], j + move[1]);
        return 0;
    }

public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        b = board;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                }
            }
        }
        int r = 0;
        for (int i = 0; i < 4; i++)
        {
            r += check(m[i], x + m[i][0], y + m[i][1]);
        }
        return r;
    }
};