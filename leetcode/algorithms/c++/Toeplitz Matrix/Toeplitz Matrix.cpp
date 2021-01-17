class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            int cur = matrix[0][i];
            for (int j = 0; j < n && j + i < m; j++)
            {
                if (cur != matrix[j][i + j])
                    return false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int cur = matrix[i][0];
            for (int j = 0; j < m && j + i < n; j++)
            {
                if (cur != matrix[i + j][j])
                    return false;
            }
        }

        return true;
    }
};