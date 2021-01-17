class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        map<vector<int>, int> base;
        map<int, vector<vector<int>>> base2;
        vector<int> keys;
        int index = 0;
        for (auto &x : intervals)
        {
            base[x] = index++;

            base2[x[0]].push_back(x);

            keys.push_back(x[0]);
        }
        sort(keys.begin(), keys.end());

        vector<int> result;
        for (auto &x : intervals)
        {
            auto low = std::lower_bound(keys.begin(), keys.end(), x[1]);
            if (low == keys.end())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(base[base2[*low].front()]);
            }
        }
        return result;
    }
};