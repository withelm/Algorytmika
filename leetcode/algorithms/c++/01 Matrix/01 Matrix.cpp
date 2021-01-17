class Solution
{
private:
    int n, m;
    vector<vector<bool>> v;

    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<int>> &l, int deep, vector<vector<int>> &matrix)
    {
        vector<vector<int>> list;
        if (l.size() == 0)
            return;
        for (auto &x : l)
        {

            if (x[0] < 0 || x[0] >= n)
                continue;
            if (x[1] < 0 || x[1] >= m)
                continue;
            if (v[x[0]][x[1]])
                continue;

            matrix[x[0]][x[1]] = deep;
            v[x[0]][x[1]] = true;
            int xx = x[0];
            int yy = x[1];

            for (auto &i : move)
            {
                list.push_back({xx + i[0], yy + i[1]});
            }
        }

        bfs(list, deep + 1, matrix);
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {

        n = matrix.size();
        m = matrix[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        v = vis;

        vector<vector<int>> list;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    list.push_back({i, j});
                    for (auto &k : move)
                    {
                        list.push_back({i + k[0], j + k[1]});
                    }
                    v[i][j] = true;
                }
            }
        }

        bfs(list, 1, matrix);

        return matrix;
    }
};