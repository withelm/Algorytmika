class Solution
{
private:
    int MX = 26;
    vector<bool> all;

    bool check(string &x)
    {
        for (auto &i : x)
        {
            if (!all[i - 'a'])
                return false;
        }
        return true;
    }

public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        all.resize(MX);
        for (auto &x : allowed)
        {
            all[x - 'a'] = true;
        }
        int r = 0;
        for (auto &x : words)
        {
            r += check(x);
        }
        return r;
    }
};