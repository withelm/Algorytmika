class Trie
{
public:
    map<char, Trie *> next;
    bool isEnd;
    string word;
    Trie()
    {
        isEnd = false;
    }
};

class Solution
{

private:
    Trie *base;

    vector<string> tmp;
    vector<vector<string>> r;

    void addToTrie(string &word, Trie *start)
    {
        for (auto &x : word)
        {
            if (start->next[x] == NULL)
                start->next[x] = new Trie();
            start = start->next[x];
        }
        start->word = word;
        start->isEnd = true;
    }

    void findWords(Trie *start)
    {
        if (start == NULL)
            return;
        if (tmp.size() > 2)
            return;
        if (start->isEnd)
        {
            tmp.push_back(start->word);
        }
        if (tmp.size() > 2)
            return;
        for (auto &x : start->next)
            findWords(x.second);
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        base = new Trie();

        for (auto &product : products)
            addToTrie(product, base);
        string tmpWord = "";
        for (auto &x : searchWord)
        {
            if (base != NULL)
                base = base->next[x];

            tmpWord += x;
            tmp.clear();
            findWords(base);
            r.push_back(tmp);
        }

        return r;
    }
};