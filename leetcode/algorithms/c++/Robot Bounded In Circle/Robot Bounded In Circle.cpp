class Solution
{
private:
    vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dic = 0;
    int x, y;
    int x_v, y_v, dic_v;
    void run(string &instructions)
    {
        for (auto &i : instructions)
        {
            if (i == 'G')
            {
                x += moves[dic][0];
                y += moves[dic][1];
            }
            if (i == 'R')
            {
                dic += 1;
            }
            if (i == 'L')
            {
                dic += 3;
            }
            dic %= 4;
        }
    }

public:
    bool isRobotBounded(string instructions)
    {
        run(instructions);
        x_v = x;
        y_v = y;
        dic_v = dic;
        return (x_v == 0 && y_v == 0) || dic_v != 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            for (int j = 0; j < instructions.size(); j++)
            {
                run(instructions);
                if (x == x_v && y == y_v && dic == dic_v)
                    return true;
            }
        }
        return false;
    }
};