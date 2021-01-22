class Solution
{
private:
    map<char, int> createMap(string &x)
    {
        map<char, int> base;
        for (auto &i : x)
            ++base[i];
        return base;
    }

    vector<int> getVect(map<char, int> &x)
    {
        vector<int> r;
        for (auto &i : x)
            r.push_back(i.second);
        sort(r.begin(), r.end());
        return r;
    }
    bool checkChars(map<char, int> &a, string &b)
    {
        for (auto &i : b)
            if (a[i] == 0)
                return false;
        return true;
    }

public:
    bool closeStrings(string word1, string word2)
    {
        auto b1 = createMap(word1);
        auto b2 = createMap(word2);
        auto v1 = getVect(b1);
        auto v2 = getVect(b2);
        if (v1.size() != v2.size())
            return false;
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                return false;

        return checkChars(b1, word2);
    }
};