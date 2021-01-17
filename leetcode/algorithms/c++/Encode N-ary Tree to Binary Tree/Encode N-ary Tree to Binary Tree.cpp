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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec
{
private:
    Node *tmp;

public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode *encode(Node *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *x = new TreeNode(root->val);
        TreeNode *y = new TreeNode(-1);
        TreeNode *it = y;
        vector<TreeNode *> t;

        for (auto &i : root->children)
        {
            if (i != NULL)
            {
                it = it->right = encode(i);
            }
        }
        x->left = y->right;
        return x;
        // tmp = root;
        //return NULL;
    }

    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        //cout << "NEW" << endl;
        // cout << root->val << endl;
        Node *x = new Node(root->val);
        auto it = root->left;
        vector<Node *> c;
        while (it != NULL)
        {
            //    cout << it->val << endl;
            c.push_back(decode(it));
            it = it->right;
        }
        x->children = c;
        return x;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));