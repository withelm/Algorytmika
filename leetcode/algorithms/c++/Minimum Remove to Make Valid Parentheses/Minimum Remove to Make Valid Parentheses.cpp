class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string r = "";
        int sum = 0;
        for (auto &x : s)
        {
            if (x == '(')
                ++sum;
            if (x == ')')
                --sum;
            if (sum < 0)
            {
                sum = 0;
                continue;
            }
            r += x;
        }
        string rr = "";
        for (int i = r.size() - 1; i >= 0; i--)
        {
            if (r[i] == '(' && sum > 0)
            {
                --sum;
                continue;
            }
            else
            {
                rr += r[i];
            }
        }
        reverse(rr.begin(), rr.end());
        return rr;
    }
};