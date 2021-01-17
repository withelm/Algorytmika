class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> t(1000 + 10, 0);
        for (auto &x : trips)
        {
            for (int i = x[1]; i < x[2]; i++)
            {
                t[i] += x[0];
                if (t[i] > capacity)
                    return false;
            }
        }
        return true;
    }
};