class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int index = 0;

        if (ruleKey == "type")
            index = 0;
        else if (ruleKey == "color")
            index = 1;
        else
            index = 2;

        int r = 0;
        for (auto &x : items)
            r += x[index] == ruleValue;
        return r;
    }
};