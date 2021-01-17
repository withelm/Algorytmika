class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int n = M.size();
        int m = M[0].size();

        vector<vector<int>> r(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = 0;
                int cnt = 0;
                for (int x_i = -1; x_i < 2; x_i++)
                {
                    for (int y_j = -1; y_j < 2; y_j++)
                    {
                        int x = i + x_i;
                        int y = j + y_j;
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            continue;
                        val += M[x][y];
                        ++cnt;
                    }
                }
                r[i][j] = val / cnt;
            }
        }
        return r;
    }
};