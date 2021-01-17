class WordDistance
{
private:
    map<string, vector<int>> base;
    int n;

public:
    WordDistance(vector<string> &words)
    {

        int tmp = 0;
        for (auto &x : words)
        {
            base[x].push_back(tmp++);
        }
        n = words.size();
    }

    int shortest(string word1, string word2)
    {
        int r = n + 100;
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

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */