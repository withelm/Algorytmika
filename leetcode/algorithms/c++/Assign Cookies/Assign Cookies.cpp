class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int r = 0;
        int n = g.size();
        int m = s.size();
        int i_n = 0;
        int i_m = 0;

        while (i_n < n && i_m < m)
        {
            while (i_m < m && s[i_m] < g[i_n])
            {
                ++i_m;
            }
            if (i_m < m && s[i_m] >= g[i_n])
            {
                ++r;
                ++i_m;
            }
            ++i_n;
        }
        return r;
    }
};