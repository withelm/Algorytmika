class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> tmp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int l = 0;
                for (int xi = max(0, i - 1); xi < min(n, i + 2); xi++)
                {
                    for (int yj = max(0, j - 1); yj < min(m, j + 2); yj++)
                    {
                        if (xi == i && yj == j)
                            continue;
                        l += board[xi][yj] == 1;
                    }
                }
                if (board[i][j] == 0)
                {
                    if (l == 3)
                        tmp[i][j] = 1;
                    else
                        tmp[i][j] = 0;
                }
                else
                {
                    // cout << i << " " << j << " " << l << endl;
                    if (l < 2)
                        tmp[i][j] = 0;
                    else if (l <= 3)
                        tmp[i][j] = 1;
                    else
                        tmp[i][j] = 0;
                }
                //cout << tmp[i][j] << " ";
            }
            //cout << endl;
        }
        board = tmp;
    }
};