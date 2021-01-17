/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
private:
    vector<Node *> inorder;
    void dfs(Node *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        inorder.push_back(x);
        dfs(x->right);
    }

public:
    Node *inorderSuccessor(Node *node)
    {
        Node *root = node;
        while (root->parent != NULL)
        {
            root = root->parent;
        }
        dfs(root);

        for (auto &x : inorder)
        {
            if (x->val > node->val)
                return x;
        }
        return NULL;
    }
};