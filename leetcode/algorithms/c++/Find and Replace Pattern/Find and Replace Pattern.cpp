class Solution
{
private:
    vector<int> normalize(string &pattern)
    {
        vector<int> result;
        for (auto &x : pattern)
            result.push_back(x - 'a');
        return result;
    }

    bool check(string word, vector<int> &norm)
    {
        if (word.size() != norm.size())
            return false;
        int n = word.size();
        set<int> isUse;
        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                if (isUse.find(norm[i]) != isUse.end())
                    return false;
                auto toReplace = word[i];
                for (int j = i; j < n; j++)
                {
                    if (word[j] == toReplace)
                        word[j] = norm[i];
                }
                isUse.insert(norm[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {

            if (word[i] != norm[i])
                return false;
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        auto p = normalize(pattern);

        vector<string> result;
        for (auto &word : words)
        {
            if (check(word, p))
                result.push_back(word);
        }
        return result;
    }
};