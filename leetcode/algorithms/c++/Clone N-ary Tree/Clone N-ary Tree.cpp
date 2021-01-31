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
    Node *cloneTree(Node *root)
    {
        if (root == NULL)
            return NULL;
        Node *x = new Node(root->val);
        for (auto &i : root->children)
            x->children.push_back(cloneTree(i));
        return x;
    }
};