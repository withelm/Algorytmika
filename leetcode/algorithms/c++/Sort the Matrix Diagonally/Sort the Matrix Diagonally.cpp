class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n && j + i < m; j++)
            {
                tmp.push_back(mat[j][i + j]);
            }
            sort(tmp.begin(), tmp.end());
            int index = 0;
            for (int j = 0; j < n && j + i < m; j++)
            {
                mat[j][i + j] = tmp[index++];
            }
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; i + j < n && j < m; j++)
            {
                tmp.push_back(mat[i + j][j]);
            }
            sort(tmp.begin(), tmp.end());
            int index = 0;
            for (int j = 0; i + j < n && j < m; j++)
            {
                mat[i + j][j] = tmp[index++];
            }
        }

        return mat;
    }
};