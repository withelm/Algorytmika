class Solution
{
private:
    int n;
    map<int, int> kub;

public:
    int leastBricks(vector<vector<int>> &wall)
    {
        n = wall.size();
        for (auto &row : wall)
        {
            int val = 0;
            for (auto &x : row)
            {
                val += x;
                ++kub[val];
            }
            --kub[val];
        }

        int maxVal = 0;
        for (auto &x : kub)
            maxVal = max(maxVal, x.second);
        return n - maxVal;
    }
};