/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    Node *findRoot(vector<Node *> tree)
    {
        map<Node *, vector<Node *>> base;
        for (auto &x : tree)
        {
            cout << x->val << " : ";
            if (base.find(x) == base.end())
            {
                base[x] = {};
            }
            for (auto &i : x->children)
            {
                base[i].push_back(x);
                cout << i->val << " ";
            }

            cout << endl;
        }
        for (auto &x : base)
        {
            //cout << x.first->val << " " << x.second.size() << endl;
            if (x.second.size() == 0)
                return x.first;
        }
        return NULL;
    }
};