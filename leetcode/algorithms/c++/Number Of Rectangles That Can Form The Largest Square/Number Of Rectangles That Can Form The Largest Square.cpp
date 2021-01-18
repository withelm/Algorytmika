class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        map<int, int> base;
        for (auto &x : rectangles)
            ++base[min(x[0], x[1])];
        return (--base.end())->second;
    }
};