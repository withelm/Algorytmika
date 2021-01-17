class Solution
{
private:
    int n, m;
    bool check(vector<vector<int>> &mat, int i, int j)
    {

        int row = 0;
        int column = 0;
        for (int k = 0; k < n; k++)
            column += mat[k][j];
        for (int k = 0; k < m; k++)
            row += mat[i][k];
        return row == 1 && column == 1;
    }

public:
    int numSpecial(vector<vector<int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1 && check(mat, i, j))
                {

                    ++r;
                }
            }
        }
        return r;
    }
};