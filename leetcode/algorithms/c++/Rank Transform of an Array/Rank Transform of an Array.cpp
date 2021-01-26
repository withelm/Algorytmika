class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> base;
        for (auto &x : arr)
            ++base[x];
        int index = 1;
        for (auto &x : base)
            x.second = index++;
        for (auto &x : arr)
            x = base[x];
        return arr;
    }
};