class Solution
{
public:
    int shortestDistance(vector<string> &words, string word1, string word2)
    {
        map<string, vector<int>> base;
        int tmp = 0;
        for (auto &x : words)
        {
            base[x].push_back(tmp++);
        }
        int r = words.size() + 100;
        for (auto &x : base[word1])
        {
            for (auto &y : base[word2])
            {
                r = min(r, abs(x - y));
            }
        }

        return r;
    }
};