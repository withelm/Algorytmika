class Solution
{

private:
    map<vector<int>, vector<vector<int>>> base;
    void init()
    {
        for (int j = 0; j < 9; j++)
        {
            for (int i = 0; i < 9; i++)
            {
                base[{j, 0, 0}].push_back({j, i});
            }
        }

        for (int j = 0; j < 9; j++)
        {
            for (int i = 1; i < 9; i++)
            {
                base[{j, i, 0}] = base[{j, 0, 0}];
            }
        }

        for (int j = 0; j < 9; j++)
        {
            for (int i = 0; i < 9; i++)
            {
                base[{0, j, 1}].push_back({i, j});
            }
        }

        for (int j = 0; j < 9; j++)
        {
            for (int i = 1; i < 9; i++)
            {
                base[{i, j, 1}] = base[{0, j, 1}];
            }
        }

        for (int ii = 0; ii <= 6; ii += 3)
        {
            for (int jj = 0; jj <= 6; jj += 3)
            {
                vector<vector<int>> tmp;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        tmp.push_back({i + ii, j + jj});
                    }
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        base[{i + ii, j + jj, 2}] = tmp;
                    }
                }
            }
        }
    }

    vector<char> lega(vector<vector<char>> &t, vector<int> find)
    {
        if (t[find[0]][find[1]] != '.')
            return {};

        vector<int> k(10, 0);

        for (int i = 0; i < 3; i++)
        {
            auto &way = base[{find[0], find[1], i}];
            for (auto &x : way)
            {
                if (t[x[0]][x[1]] != '.')
                    ++k[t[x[0]][x[1]] - '0'];
            }
        }
        vector<char> result;
        for (int i = 1; i <= 9; i++)
        {
            if (k[i] == 0)
                result.push_back(i + '0');
        }
        return result;
    }
    bool oblivius(vector<vector<char>> &t)
    {
        bool isUp = false;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (t[i][j] == '.')
                {
                    auto tmp = lega(t, {i, j});
                    if (tmp.size() == 1)
                    {
                        t[i][j] = tmp[0];
                        isUp = true;
                    }
                }
            }
        }
        return isUp;
    }

    bool stop = false;

    bool check(vector<vector<char>> &t)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (t[i][j] == '.')
                    return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<char>> &t)
    {
        if (stop)
            return;
        pirnt(t);
        if (check(t))
        {
            stop = true;
            return;
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                auto next = lega(t, {i, j});
                if (t[i][j] == '.' && next.size() == 0)
                {
                    //  cout << "ERROR " << i << " " << j << endl;
                    return;
                }
                for (auto &x : next)
                {
                    t[i][j] = x;
                    dfs(t);
                    if (stop)
                        return;
                    //cout <<"BACK " << i << " " << j << " | " << x << endl;
                    t[i][j] = '.';
                }
                if (t[i][j] == '.')
                    return;
            }
        }
    }

    void pirnt(vector<vector<char>> &x)
    { /*
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << x[i][j];
                if (j % 3 == 2) cout << " ";
            }
            cout << endl;
        }
        cout << endl;*/
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        init();
        //  while(oblivius(board));
        dfs(board);
    }
};