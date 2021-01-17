class Solution
{
private:
    int n, m;
    int calc(int x, int y, int k, vector<vector<int>> &mat)
    {
        long long int result = 0;
        for (int i = max(x - k, 0); i <= min(n - 1, x + k); i++)
        {
            for (int j = max(y - k, 0); j <= min(m - 1, y + k); j++)
            {
                //cout << i << " " << j << endl;
                result += mat[i][j];
            }
        }
        return result;
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> r(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout <<"calc " << i << " " << j << endl;
                r[i][j] = calc(i, j, K, mat);
            }
        }
        return r;
    }
};