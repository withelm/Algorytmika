class TicTacToe
{
private:
    int n;
    map<int, map<int, int>> rows;
    map<int, map<int, int>> columns;

    map<int, int> firstCross;
    map<int, int> secondCross;

public:
    /** Initialize your data structure here. */
    TicTacToe(int _n)
    {
        n = _n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        ++rows[row][player];
        ++columns[col][player];
        if (rows[row][player] == n)
            return player;
        if (columns[col][player] == n)
            return player;

        if (row == col)
        {
            ++firstCross[player];
            if (firstCross[player] == n)
                return player;
        }
        if (row + col == n - 1)
        {
            ++secondCross[player];
            if (secondCross[player] == n)
                return player;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */