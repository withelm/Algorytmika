class Trie
{

public:
    vector<Trie *> next;
    bool isEnd;
    Trie()
    {
        isEnd = false;
        next = vector<Trie *>(256, NULL);
    }
};

class FullTrie
{
private:
    Trie *root;

public:
    FullTrie()
    {
        root = new Trie();
    }
    void insert(string s)
    {
        Trie *node = root;
        for (auto &x : s)
        {
            if (node->next[x] == NULL)
            {
                node->next[x] = new Trie();
            }
            node = node->next[x];
        }
        node->isEnd = true;
    }
    bool isExist(vector<char> &x)
    {
        Trie *node = root;
        for (auto &i : x)
        {
            if (node->next[i] == NULL)
                return false;
            node = node->next[i];
            if (node->isEnd)
                return true;
        }
        return node->isEnd;
    }
};

class StreamChecker
{
private:
    FullTrie root;
    int max_k;
    vector<char> tmp;

public:
    StreamChecker(vector<string> &words)
    {
        max_k = 0;
        for (auto &x : words)
        {
            reverse(x.begin(), x.end());
            root.insert(x);
            max_k = max(max_k, (int)x.size());
        }
    }

    bool query(char letter)
    {
        tmp.insert(tmp.begin(), letter);
        if (tmp.size() > max_k)
        {
            tmp.pop_back();
        }
        return root.isExist(tmp);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */