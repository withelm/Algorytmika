class Solution
{
private:
    set<vector<int>> base;
    vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dic = 0;

    bool check(int x, int y, int dic)
    {
        int new_x = x + moves[dic][0];
        int new_y = y + moves[dic][1];

        return base.find({new_y, new_x}) == base.end();
    }

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        for (auto &x : obstacles)
        {
            base.insert({x[1], x[0]});
        }

        int n = commands.size();
        int x = 0;
        int y = 0;
        int result = 0;
        for (int i = 0; i < n; i++)
        {

            if (commands[i] == -2)
            {
                dic = (dic - 1 + 4) % 4;
                continue;
            }
            if (commands[i] == -1)
            {
                dic = (dic + 1) % 4;
                continue;
            }

            for (int j = 0; j < commands[i]; j++)
            {
                if (check(x, y, dic))
                {
                    x += moves[dic][0];
                    y += moves[dic][1];
                    result = max(result, x * x + y * y);
                }
                else
                {
                    break;
                }
            }
        }
        return result;
    }
};