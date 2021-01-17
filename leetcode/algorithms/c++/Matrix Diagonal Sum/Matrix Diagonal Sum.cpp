class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        map<vector<int>, int> base;
        int result = 0;
        for (int i = 0; i < min(n, m); i++)
        {
            result += mat[i][i];

            ++base[{i, i}];
        }
        for (int i = 0; i < n; i++)
        {
            if (base[{m - 1 - i, i}] == 0)
            {
                result += mat[m - i - 1][i];
            }
        }

        return result;
    }
};