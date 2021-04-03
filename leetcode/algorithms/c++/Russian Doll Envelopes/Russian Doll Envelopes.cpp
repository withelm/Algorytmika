class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &t)
    {
        sort(t.begin(), t.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        int n = t.size();
        vector<int> r(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (t[i][0] > t[j][0] && t[i][1] > t[j][1])
                {
                    r[i] = max(r[i], r[j] + 1);
                }
            }
        }

        return *max_element(r.begin(), r.end());
    }
};