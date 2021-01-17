class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, int> base;
        for (auto &x : paths)
        {
            base[x[0]] = 0;
            base[x[1]] = 0;
        }
        for (auto &x : paths)
        {
            ++base[x[0]];
        }
        for (auto &x : base)
        {
            if (x.second == 0)
                return x.first;
        }
        return "";
    }
};