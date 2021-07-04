class Solution
{
private:
    bool isPal(string &word, int left, int right)
    {
        while (left < right)
        {
            if (word[left] != word[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }

    string substring(string &word, int left, int right)
    {
        string r = "";
        for (int i = left; i < right; i++)
        {
            r += word[i];
        }
        return r;
    }

    vector<string> getPref(string &word)
    {
        vector<string> res;
        for (int i = 0; i < word.size(); i++)
        {
            if (isPal(word, i, word.size() - 1))
                res.push_back(substring(word, 0, i));
        }
        return res;
    }

    vector<string> getSuff(string &word)
    {
        vector<string> res;
        for (int i = 0; i < word.size(); i++)
        {
            if (isPal(word, 0, i))
                res.push_back(substring(word, i + 1, word.size()));
        }
        return res;
    }

    map<string, int> base;

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
            base[words[i]] = i;

        vector<vector<int>> res;

        for (auto &item : base)
        {
            auto word = item.first;
            int currIndex = item.second;
            string revers = string(word.rbegin(), word.rend());

            if (base.find(revers) != base.end() && base[revers] != currIndex)
                res.push_back({currIndex, base[revers]});

            for (auto suff : getSuff(word))
            {
                string revSuff = string(suff.rbegin(), suff.rend());
                if (base.find(revSuff) != base.end())
                    res.push_back({base[revSuff], currIndex});
            }

            for (auto pref : getPref(word))
            {
                string revPref = string(pref.rbegin(), pref.rend());
                if (base.find(revPref) != base.end())
                    res.push_back({currIndex, base[revPref]});
            }
        }
        return res;
    }
};