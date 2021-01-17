class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> base;
        for (auto x : arr)
            ++base[x];

        int r = -1;
        for (auto &x : base)
        {
            if (x.first == x.second)
                r = x.first;
        }
        return r;
    }
};