class Solution
{
private:
    map<int, int> base;

public:
    int smallestCommonElement(vector<vector<int>> &mat)
    {
        int n = mat.size();
        for (auto &i : mat)
        {
            for (auto &j : i)
            {
                ++base[j];
            }
        }
        for (auto &x : base)
            if (x.second == n)
                return x.first;
        return -1;
    }
};