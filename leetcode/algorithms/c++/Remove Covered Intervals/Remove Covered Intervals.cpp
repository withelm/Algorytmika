

class Solution
{
private:
    bool check(vector<int> &x, vector<int> &y)
    {
        return (x[0] <= y[0] && x[1] >= y[1]);
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<bool> v(n + 10, false);
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && check(intervals[i], intervals[j]))
                {
                    v[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!v[i])
                ++r;
        }
        return r;
    }
};