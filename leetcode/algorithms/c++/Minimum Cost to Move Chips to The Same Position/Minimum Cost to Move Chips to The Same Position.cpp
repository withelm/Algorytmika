class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        vector<int> k(2, 0);
        for (auto &x : position)
            ++k[x % 2];
        return min(k[0], k[1]);
    }
};