class Node
{
public:
    vector<Node *> t;
    int val;
    Node()
    {
        t.resize(26);
        val = 0;
    }
};

class MapSum
{
private:
    Node *root;

    int dfs(Node *x)
    {
        if (x == NULL)
            return 0;
        int r = x->val;
        for (auto &i : x->t)
            r += dfs(i);
        return r;
    }

public:
    /** Initialize your data structure here. */
    MapSum()
    {
        root = new Node();
    }

    void insert(string key, int val)
    {
        Node *tmp = root;
        for (auto &x : key)
        {
            if (tmp->t[x - 'a'] == NULL)
            {
                tmp->t[x - 'a'] = new Node();
            }
            tmp = tmp->t[x - 'a'];
        }
        tmp->val = val;
    }

    int sum(string prefix)
    {
        Node *tmp = root;
        for (auto &x : prefix)
        {
            if (tmp->t[x - 'a'] == NULL)
            {
                return 0;
            }
            tmp = tmp->t[x - 'a'];
        }
        return dfs(tmp);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */