class Trie
{
public:
    Trie()
    {
        isEnd = false;
        child.resize(26, NULL);
    }
    vector<Trie *> child;
    bool isEnd;
};

bool add(string x, Trie *t)
{
    for (int i = 0; i < 10; i++)
    {
        if (t->child[x[i] - 'A'] == NULL)
            t->child[x[i] - 'A'] = new Trie();
        t = t->child[x[i] - 'A'];
    }
    if (t->isEnd)
        return true;
    t->isEnd = true;
    return false;
}

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        set<string> r;
        Trie *t = new Trie();
        for (int i = 0; i <= n - 10; i++)
        {
            string acc = "";
            for (int j = 0; j < 10; j++)
                acc += s[i + j];
            // cout << acc << endl;
            if (add(acc, t))
                r.insert(acc);
        }

        return vector<string>(r.begin(), r.end());
    }
};