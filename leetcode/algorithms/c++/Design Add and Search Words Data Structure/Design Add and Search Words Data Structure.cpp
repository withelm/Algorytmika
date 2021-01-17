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

class WordDictionary
{
private:
    Node *root;
    string search2;
    int n;

    bool dfs(Node *x, int index)
    {
        if (x == NULL)
            return false;
        if (index == n)
        {

            return x->isEnd;
        }
        if (search2[index] != '.')
        {
            //  cout << search2[index] << " ";
            return dfs(x->t[search2[index] - 'a'], index + 1);
        }
        else
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (dfs(x->t[i - 'a'], index + 1))
                    return true;
            }
        }
        return false;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
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

    bool search(string word)
    {
        //   cout << word << endl;
        search2 = word;
        n = word.size();
        return dfs(root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */