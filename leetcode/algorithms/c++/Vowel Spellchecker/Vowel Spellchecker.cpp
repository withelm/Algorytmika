class Solution
{
private:
    map<string, vector<string>> base;
    map<string, vector<string>> toLow;
    map<string, vector<string>> toAll;

    string toConvLow(string x)
    {
        string r = "";
        for (auto &i : x)
        {
            if (i >= 'A' && i <= 'Z')
                r += i - 'A' + 'a';
            else
                r += i;
        }
        return r;
    }

    string toConvAll(string x)
    {
        string r = toConvLow(x);
        //('a', 'e', 'i', 'o', 'u')
        for (auto &i : r)
        {
            if (i == 'a')
                i = '*';
            if (i == 'e')
                i = '*';
            if (i == 'i')
                i = '*';
            if (i == 'o')
                i = '*';
            if (i == 'u')
                i = '*';
        }
        return r;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        for (auto &x : wordlist)
        {
            base[x].push_back(x);
            toLow[toConvLow(x)].push_back(x);
            toAll[toConvAll(x)].push_back(x);
        }

        vector<string> r;
        for (auto &x : queries)
        {
            if (base[x].size() > 0)
            {
                r.push_back(base[x][0]);
                continue;
            }
            if (toLow[toConvLow(x)].size() > 0)
            {
                r.push_back(toLow[toConvLow(x)][0]);
                continue;
            }
            if (toAll[toConvAll(x)].size() > 0)
            {
                r.push_back(toAll[toConvAll(x)][0]);
                continue;
            }
            r.push_back("");
        }

        return r;
    }
};