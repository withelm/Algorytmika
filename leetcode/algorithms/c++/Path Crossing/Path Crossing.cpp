class Solution
{

public:
    bool isPathCrossing(string path)
    {
        map<char, vector<int>> way;
        way['N'] = {1, 0};
        way['S'] = {-1, 0};
        way['E'] = {0, 1};
        way['W'] = {0, -1};

        set<vector<int>> vis;
        int x = 0;
        int y = 0;
        vis.insert({x, y});
        for (auto &item : path)
        {
            x += way[item][0];
            y += way[item][1];
            if (vis.find({x, y}) != vis.end())
                return true;
            vis.insert({x, y});
        }
        return false;
    }
};