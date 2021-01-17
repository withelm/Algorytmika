/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int left(TreeNode *x)
    {
        x = x->right;
        while (x->left != NULL)
            x = x->left;
        return x->val;
    }
    int right(TreeNode *x)
    {
        x = x->left;
        while (x->right != NULL)
            x = x->right;
        return x->val;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            else if (root->right != NULL)
            {
                root->val = left(root);
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = right(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};