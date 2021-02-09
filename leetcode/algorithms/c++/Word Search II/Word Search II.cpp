class Solution
{
private:
    vector<vector<int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<char>> t;
    string w;

    bool find(int x, int y, int i)
    {
        if (i == w.size())
            return true;
        if (t[x][y] == w[i])
        {
            auto tmp = t[x][y];
            t[x][y] = '#';
            for (auto &move : moves)
            {
                if (find(x + move[0], y + move[1], i + 1))
                {
                    t[x][y] = tmp;
                    return true;
                }
            }
            t[x][y] = tmp;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        w = word;

        for (int i = 1; i < board.size() - 1; i++)
        {
            for (int j = 1; j < board[i].size() - 1; j++)
            {
                if (find(i, j, 0))
                    return true;
            }
        }

        return false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<char> limit(board[0].size(), '#');
        board.insert(board.begin(), limit);
        board.push_back(limit);

        for (auto &x : board)
        {
            x.insert(x.begin(), '#');
            x.push_back('#');
        }
        t = board;

        vector<string> r;
        for (auto &x : words)
        {
            if (exist(board, x))
                r.push_back(x);
        }
        return r;
    }
};