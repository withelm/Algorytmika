bool cmp(vector<int> &x, vector<int> &y)
{
    return x[0] < y[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> r;
        if (intervals.size() == 0)
            return r;
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<int> tmp = intervals[0];
        for (int i = 1; i < n; i++)
        {
            if (tmp[1] >= intervals[i][0])
            {
                tmp[1] = max(intervals[i][1], tmp[1]);
            }
            else
            {
                r.push_back(tmp);
                tmp = intervals[i];
            }
        }
        r.push_back(tmp);
        return r;
    }
};