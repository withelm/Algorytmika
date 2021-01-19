class Solution
{
private:
    vector<string> words = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    map<char, int> base;

    bool check(string &x)
    {
        if (x.size() == 0)
            return true;
        int first = base[tolower(x[0])];
        for (auto &i : x)
        {
            if (first != base[tolower(i)])
                return false;
        }
        return true;
    }

public:
    vector<string> findWords(vector<string> &t)
    {
        vector<string> r;

        for (int i = 0; i < 3; i++)
        {
            for (auto &x : words[i])
            {
                base[x] = i;
            }
        }

        for (auto &x : t)
        {
            if (check(x))
                r.push_back(x);
        }
        return r;
    }
};