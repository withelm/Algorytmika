class Solution
{
public:
    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        map<vector<int>, vector<string>> base;
        for (auto &x : strings)
        {
            vector<int> t = {0};
            for (int i = 1; i < x.size(); i++)
                t.push_back((x[0] - x[i] + 26) % 26);
            base[t].push_back(x);
        }
        vector<vector<string>> r;
        for (auto &x : base)
            r.push_back(x.second);
        return r;
    }
};