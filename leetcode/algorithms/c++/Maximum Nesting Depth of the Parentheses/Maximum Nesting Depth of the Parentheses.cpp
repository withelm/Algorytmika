class Solution
{
public:
    int maxDepth(string s)
    {
        int r = 0;
        int tmp = 0;
        for (auto &x : s)
        {
            if (x == '(')
                ++tmp;
            if (x == ')')
                --tmp;
            r = max(r, tmp);
        }
        return r;
    }
};