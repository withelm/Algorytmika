class Solution
{
private:
    bool cmp(string &x, string &y, map<char, int> &dic)
    {
        int n = x.size();
        int m = y.size();
        for (int i = 0; i < min(n, m); i++)
        {
            if (dic[x[i]] < dic[y[i]])
                return true;
            if (dic[x[i]] > dic[y[i]])
                return false;
        }
        return n <= m;
    }

public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> dic;
        int index = 0;
        for (auto &x : order)
        {
            dic[x] = index++;
        }
        for (int i = 1; i < words.size(); i++)
        {
            if (!cmp(words[i - 1], words[i], dic))
                return false;
        }
        return true;
    }
};