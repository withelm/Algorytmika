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
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d, int deep = 1)
    {
        if (root == NULL)
            return NULL;
        if (d == 1)
        {
            auto left = new TreeNode();
            left->val = v;
            left->left = root;

            return left;
        }
        if (deep == d - 1)
        {
            auto left = new TreeNode();
            left->val = v;
            left->left = root->left;
            root->left = left;
            auto right = new TreeNode();
            right->val = v;
            right->right = root->right;
            root->right = right;
            return root;
        }
        root->left = addOneRow(root->left, v, d, deep + 1);
        root->right = addOneRow(root->right, v, d, deep + 1);
        return root;
    }
};