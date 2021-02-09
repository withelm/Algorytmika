class ValidWordAbbr
{
private:
    map<string, vector<string>> base;

    string getAbbr(string &x)
    {
        if (x.size() < 3)
            return x;
        return x[0] + to_string(x.size() - 2) + x[x.size() - 1];
    }

public:
    ValidWordAbbr(vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end());
        dictionary.erase(unique(dictionary.begin(), dictionary.end()), dictionary.end());
        for (auto &x : dictionary)
            base[getAbbr(x)].push_back(x);
    }

    bool isUnique(string word)
    {
        auto abbr = getAbbr(word);
        if (base.find(abbr) == base.end())
            return true;
        if (base[abbr].size() > 1)
            return false;
        return base[abbr][0] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */