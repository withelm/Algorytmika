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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<Node *> t;
        vector<Node *> next;
        vector<vector<int>> r;
        if (root == NULL)
            return r;

        t.push_back(root);
        r.push_back({root->val});

        while (t.size() > 0)
        {
            vector<int> tmp;
            for (auto &x : t)
            {
                for (auto &i : x->children)
                {
                    next.push_back(i);
                    tmp.push_back(i->val);
                }
            }
            if (tmp.size() > 0)
                r.push_back(tmp);
            t = next;
            next.clear();
        }
        return r;
    }
};