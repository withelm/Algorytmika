class Solution
{
private:
public:
    vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
    {
        sort(slots1.begin(), slots1.end(), [](const vector<int> &x, const vector<int> &y) {
            return x[0] < y[0];
        });
        sort(slots2.begin(), slots2.end(), [](const vector<int> &x, const vector<int> &y) {
            return x[0] < y[0];
        });

        int i = 0;
        int j = 0;
        int n = slots1.size();
        int m = slots2.size();

        while (i < n && j < m)
        {
            int _begin = max(slots1[i][0], slots2[j][0]);
            int _end = min(slots1[i][1], slots2[j][1]);
            if (_begin + duration <= _end)
                return {_begin, _begin + duration};
            if (slots1[i][1] < slots2[j][1])
                ++i;
            else
                ++j;
        }
        return {};
    }
};