class Solution
{
private:
    int INF = 101;
    double max(double a, double b)
    {
        return a > b ? a : b;
    }
    double min(double a, double b)
    {
        return a < b ? a : b;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> t(INF, vector<double>(INF, 0.0));

        t[0][0] = poured;
        for (int i = 1; i < INF; i++)
        {
            for (int j = 0; j < INF; j++)
            {
                double left = 0.0;
                double right = 0.0;
                if (j != 0)
                {
                    left = max((t[i - 1][j - 1] - 1) / 2, 0);
                }
                if (j + 1 != INF)
                {
                    right = max(0, (t[i - 1][j] - 1) / 2);
                }
                t[i][j] = left + right;
                // if (t[i][j] != 0)
                //     cout << i << " " << j << " " << t[i][j] << endl;
            }
        }
        return min(t[query_row][query_glass], 1);
    }
};