class Solution
{
private:
    set<string> base;
    bool check(string &x)
    {
        for (int i = x.size() - 1; i > 0; i--)
        {
            if (base.find(x.substr(0, i)) == base.end())
                return false;
        }
        return true;
    }

public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &x, const string &y) {
            if (x.size() == y.size())
            {
                return x < y;
            }

            return x.size() > y.size();
        });

        for (auto &x : words)
            base.insert(x);

        for (auto &x : words)
        {
            if (check(x))
                return x;
        }
        return "";
    }
};