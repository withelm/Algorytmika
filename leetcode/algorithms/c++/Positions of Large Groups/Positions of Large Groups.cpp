class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        if (s.size() == 0)
            return {{}};
        int start = 0;
        char zn = s[0];
        vector<vector<int>> r;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != zn)
            {
                if (i - start >= 3)
                {
                    r.push_back({start, i - 1});
                }
                start = i;
                zn = s[i];
            }
        }
        if (s.size() - start >= 3)
            r.push_back({start, (int)s.size() - 1});
        return r;
    }
};