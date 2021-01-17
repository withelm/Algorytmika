class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int n = intervals.size();
        int index = 0;
        while (index < n && intervals[index][1] < newInterval[0])
        {
            //cout << "Add " << intervals[index][0] << " " << intervals[index][1] << endl;
            result.push_back(intervals[index]);
            index++;
        }

        int a = newInterval[0];
        int b = newInterval[1];
        // cout << a << " " << b << endl;
        while (index < n && intervals[index][0] <= newInterval[1])
        {
            //cout << "Upgrade " << intervals[index][0] << " " << intervals[index][1] << endl;
            a = min(a, intervals[index][0]);
            b = max(b, intervals[index][1]);
            //cout << a << " " << b << endl;
            ++index;
        }
        result.push_back({a, b});
        for (; index < n; index++)
        {
            //cout << "End " << intervals[index][0] << " " << intervals[index][1] << endl;
            result.push_back(intervals[index]);
        }
        return result;
    }
};