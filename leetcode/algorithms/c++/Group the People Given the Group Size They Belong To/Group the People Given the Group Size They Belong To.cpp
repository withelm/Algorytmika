class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        map<int, vector<int>> base;

        for (int i = 0; i < n; i++)
            base[groupSizes[i]].push_back(i);
        vector<vector<int>> r;
        for (auto &x : base)
        {
            for (int i = 0; i < x.second.size(); i += x.first)
            {
                vector<int> tmp;
                for (int j = i; j < i + x.first; j++)
                {
                    tmp.push_back(x.second[j]);
                }
                r.push_back(tmp);
            }
        }
        return r;
    }
};