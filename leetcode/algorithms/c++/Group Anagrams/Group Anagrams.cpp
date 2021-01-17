class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> datas;
        for (auto &x : strs)
        {
            vector<int> t(255, 0);
            for (auto &i : x)
                ++t[i];
            datas[t].push_back(x);
        }
        vector<vector<string>> r;
        for (auto &x : datas)
            r.push_back(x.second);
        return r;
    }
};