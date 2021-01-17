class Solution
{
public:
    int largestUniqueNumber(vector<int> &A)
    {
        map<int, int> t;
        for (auto &x : A)
        {
            ++t[x];
        }
        int result = -1;
        for (auto &x : t)
        {
            if (x.second == 1)
            {
                result = max(result, x.first);
            }
        }
        return result;
    }
};