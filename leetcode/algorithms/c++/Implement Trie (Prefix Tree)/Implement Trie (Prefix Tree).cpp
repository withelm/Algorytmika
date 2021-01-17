class Node
{
public:
    vector<Node *> t;
    bool isEnd;
    Node()
    {
        t.resize(26);
        isEnd = false;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *tmp = root;
        for (auto &i : word)
        {
            if (tmp->t[i - 'a'] == NULL)
            {
                tmp->t[i - 'a'] = new Node();
            }
            tmp = tmp->t[i - 'a'];
        }
        tmp->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *tmp = root;
        for (auto &i : word)
        {
            if (tmp->t[i - 'a'] == NULL)
            {
                return false;
            }
            tmp = tmp->t[i - 'a'];
        }
        return tmp->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *tmp = root;
        for (auto &i : prefix)
        {
            if (tmp->t[i - 'a'] == NULL)
            {
                return false;
            }
            tmp = tmp->t[i - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */