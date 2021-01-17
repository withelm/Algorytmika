class Solution
{
private:
    string getStr(int x, int n)
    {
        string v = "";
        for (int i = 0; i < n; i++)
        {
            if (x % 2 == 0)
                v += '(';
            else
                v += ')';
            x /= 2;
        }
        return v;
    }
    bool check(string v)
    {
        int k = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == '(')
                ++k;
            else
                --k;
            if (k < 0)
                return false;
        }
        return k == 0;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        int limit = (1 << (2 * n));
        vector<string> r;
        for (int i = 0; i < limit; i++)
        {
            auto str = getStr(i, 2 * n);
            if (check(str))
            {
                r.push_back(str);
            }
        }

        return r;
    }
};