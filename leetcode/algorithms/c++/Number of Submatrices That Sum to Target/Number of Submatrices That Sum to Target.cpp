class Solution
{
private:
    int n, m;
    vector<vector<int>> pref;

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        n = matrix.size();
        if (n == 0)
            return 0;
        m = matrix[0].size();

        pref.resize(n + 1);
        for (int i = 0; i <= n; i++)
            pref[i].resize(m + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                for (int x = i + 1; x <= n; x++)
                {
                    for (int y = j + 1; y <= m; y++)
                    {
                        int sum = pref[x][y] - pref[i][y] - pref[x][j] + pref[i][j];

                        r += sum == target;
                    }
                }
            }
        }
        return r;
    }
};