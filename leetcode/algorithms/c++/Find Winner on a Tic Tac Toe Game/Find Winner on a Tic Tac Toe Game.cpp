class Solution
{
private:
    bool isFull(vector<vector<int>> &game)
    {
        int cnt = 0;
        for (auto &i : game)
        {
            for (auto &j : i)
            {
                cnt += j != 0;
            }
        }
        return cnt == 9;
    }

    bool isWin(vector<vector<int>> &game, int num)
    {
        for (int i = 0; i < 3; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 3; j++)
            {
                cnt += game[i][j] == num;
            }
            if (cnt == 3)
                return true;
            cnt = 0;
            for (int j = 0; j < 3; j++)
            {
                cnt += game[j][i] == num;
            }
            if (cnt == 3)
                return true;
        }
        return (game[0][0] == num && game[1][1] == num && game[2][2] == num) || (game[0][2] == num && game[1][1] == num && game[2][0] == num);
    }

    string getStatus(vector<vector<int>> &game)
    {
        if (isWin(game, 1))
        {
            return "A";
        }
        if (isWin(game, 2))
        {
            return "B";
        }
        if (isFull(game))
        {
            return "Draw";
        }
        return "Pending";
    }

public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<vector<int>> game(3, vector<int>(3, 0));

        int i = 0;
        while (getStatus(game) == "Pending" && i < moves.size())
        {
            game[moves[i][0]][moves[i][1]] = (i % 2 == 0) ? 1 : 2;
            ++i;
        }

        return getStatus(game);
    }
};