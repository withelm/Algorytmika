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
private:
    vector<int> v;
    void dfs(Node *x)
    {
        if (x == NULL)
            return;
        v.push_back(x->val);
        for (auto &i : x->children)
        {
            dfs(i);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        dfs(root);
        return v;
    }
};