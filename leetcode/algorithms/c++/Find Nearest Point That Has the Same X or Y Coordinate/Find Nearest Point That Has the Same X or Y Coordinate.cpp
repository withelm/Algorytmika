class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        map<int, int> base;
        int index = 0;
        for (auto &item : points)
        {
            if (x == item[0] || y == item[1])
            {
                int key = abs(x - item[0]) + abs(y - item[1]);
                if (base.find(key) == base.end())
                    base[key] = index;
            }
            index++;
        }
        for (auto &item : base)
            return item.second;
        return -1;
    }
};