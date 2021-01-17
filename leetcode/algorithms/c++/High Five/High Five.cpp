class Solution
{
public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        map<int, vector<int>> base;
        for (auto &x : items)
        {
            base[x[0]].push_back(x[1]);
        }
        vector<vector<int>> result;
        for (auto &x : base)
        {
            sort(x.second.begin(), x.second.end());
            int index = 0;
            int suma = 0;
            for (int i = x.second.size() - 1; i >= 0; i--)
            {
                if (index >= 5)
                    break;
                ++index;
                suma += x.second[i];
            }
            result.push_back({x.first, suma / min(5, (int)x.second.size())});
        }
        return result;
    }
};