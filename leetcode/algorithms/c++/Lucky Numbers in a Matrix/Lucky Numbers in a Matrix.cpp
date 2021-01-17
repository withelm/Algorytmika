class Solution
{
private:
    int n, m;
    bool check(int x, int y, vector<vector<int>> &matrix)
    {
        for (int i = 0; i < m; i++)
        {
            if (matrix[x][i] < matrix[x][y])
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][y] > matrix[x][y])
                return false;
        }
        return true;
    }

public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check(i, j, matrix))
                    r.push_back(matrix[i][j]);
            }
        }
        return r;
    }
};