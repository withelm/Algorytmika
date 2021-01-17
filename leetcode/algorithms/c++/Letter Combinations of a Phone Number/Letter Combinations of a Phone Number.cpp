class Solution
{
private:
    map<char, vector<char>> base;

    void init()
    {
        base['9'] = {'w', 'x', 'y', 'z'};
        base['8'] = {'t', 'u', 'v'};
        base['7'] = {'p', 'q', 'r', 's'};
        base['6'] = {'m', 'n', 'o'};
        base['5'] = {'j', 'k', 'l'};
        base['4'] = {'g', 'h', 'i'};
        base['3'] = {'d', 'e', 'f'};
        base['2'] = {'a', 'b', 'c'};
    }

    vector<string> dfs(string x)
    {
        if (x.size() == 0)
            return {};
        if (x.size() == 1)
        {
            vector<string> r;
            for (auto &x : base[x[0]])
            {
                string tmp;
                tmp += x;
                r.push_back(tmp);
            }
            return r;
        }
        char last_char = x.back();
        x.pop_back();

        vector<string> r;
        for (auto &i : dfs(x))
        {
            for (auto &j : base[last_char])
            {
                r.push_back(i + j);
            }
        }

        return r;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        init();

        return dfs(digits);
    }
};