class Solution
{
private:
    string removeLast(string x)
    {
        if (x.size() == 0)
            return x;
        return x.substr(0, x.size() - 1);
    }
    string check(string S)
    {
        string r = "";
        for (auto &x : S)
        {
            if (x != '#')
            {
                r += x;
            }
            else
            {
                r = removeLast(r);
            }
        }
        return r;
    }

public:
    bool backspaceCompare(string S, string T)
    {
        return check(S) == check(T);
    }
};