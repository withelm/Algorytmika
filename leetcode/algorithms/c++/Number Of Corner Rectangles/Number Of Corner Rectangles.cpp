class Solution
{
public:
    int countCornerRectangles(vector<vector<int>> &t)
    {
        int n = t.size();
        int m = t[0].size();
        int r = 0;
        vector<vector<int>> row, col;
        row.resize(n);
        col.resize(m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] == 1)
                {
                    row[i].push_back(j);
                    col[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] == 1)
                {
                    for (auto &x : row[i])
                    {
                        for (auto &y : col[j])
                        {
                            if (x > j && y > i)
                            {
                                // cout << i << " " << j << " | " << x << " " << y << endl;
                                r += t[y][x] == 1;
                            }
                        }
                    }
                }
            }
        }

        return r;
    }
};