class Solution
{
private:
    int n = 9;

    bool check(vector<char> chars)
    {
        vector<char> t;
        for (auto &x : chars)
            if (x != '.')
                t.push_back(x);

        if (t.size() < 2)
            return true;
        sort(t.begin(), t.end());
        for (int i = 1; i < t.size(); i++)
            if (t[i - 1] == t[i])
                return false;
        return true;
    }

    bool checkRows(vector<vector<char>> &board)
    {
        for (auto &x : board)
        {
            if (!check(x))
                return false;
        }
        return true;
    }

    bool checkColumns(vector<vector<char>> &board)
    {
        for (int i = 0; i < n; i++)
        {
            vector<char> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(board[j][i]);
            if (!check(tmp))
                return false;
        }
        return true;
    }

    bool checkRecs(vector<vector<char>> &board)
    {
        for (int i = 0; i < n; i += 3)
        {
            for (int j = 0; j < n; j += 3)
            {
                vector<char> tmp;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        tmp.push_back(board[x][y]);
                    }
                }
                if (!check(tmp))
                    return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return checkRows(board) && checkColumns(board) && checkRecs(board);
    }
};