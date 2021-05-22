class Solution
{
private:
    vector<vector<string>> res;
    int n;

    vector<string> t;

    void dfs(int level)
    {

        if (level == n)
        {
            res.push_back(t);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (t[level][i] == '#')
            {
                vector<vector<int>> updatePoint;

                for (int j = 0; j < n; j++)
                {
                    if (t[level][j] == '#')
                    {

                        updatePoint.push_back({level, j});
                        t[level][j] = '.';
                    }
                    if (t[j][i] == '#')
                    {

                        updatePoint.push_back({j, i});
                        t[j][i] = '.';
                    }
                }

                for (int j = 0; j < n; j++)
                {
                    if (level - j >= 0 && i + j < n)
                    {
                        if (t[level - j][i + j] == '#')
                        {
                            updatePoint.push_back({level - j, i + j});
                            t[level - j][i + j] = '.';
                        }
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (level + j < n && i - j >= 0)
                    {
                        if (t[level + j][i - j] == '#')
                        {
                            updatePoint.push_back({level + j, i - j});
                            t[level + j][i - j] = '.';
                        }
                    }
                }

                for (int j = 0; j < n; j++)
                {
                    if (level - j >= 0 && i - j >= 0)
                    {
                        if (t[level - j][i - j] == '#')
                        {
                            updatePoint.push_back({level - j, i - j});
                            t[level - j][i - j] = '.';
                        }
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (level + j < n && i + j < n)
                    {
                        if (t[level + j][i + j] == '#')
                        {
                            updatePoint.push_back({level + j, i + j});
                            t[level + j][i + j] = '.';
                        }
                    }
                }

                t[level][i] = 'Q';

                dfs(level + 1);

                for (auto &item : updatePoint)
                {

                    t[item[0]][item[1]] = '#';
                }
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int _n)
    {
        n = _n;
        t.resize(n);
        for (auto &x : t)
        {
            x.resize(n);
            for (auto &i : x)
                i = '#';
        }

        dfs(0);
        return res;
    }
};