class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int sum = 0;
        int r = 1;
        for (auto &x : s)
        {
            if (sum + widths[x - 'a'] > 100)
            {
                ++r;
                sum = widths[x - 'a'];
            }
            else
            {
                sum += widths[x - 'a'];
            }
        }
        return {r, sum};
    }
};