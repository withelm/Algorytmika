class Solution
{
public:
    bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs)
    {
        if (sentence1.size() != sentence2.size())
            return false;

        unordered_map<string, unordered_set<string>> base;
        for (auto &x : similarPairs)
        {
            base[x[0]].insert(x[1]);
            base[x[1]].insert(x[0]);
        }

        for (int i = 0; i < sentence1.size(); i++)
        {
            if (sentence1[i] == sentence2[i])
                continue;
            if (base[sentence1[i]].find(sentence2[i]) == base[sentence1[i]].end())
                return false;
        }
        return true;
    }
};