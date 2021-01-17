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
    unordered_map<TreeNode *, int> base;

public:
    inline int rob(TreeNode *root)
    {
        if (root == NULL)
        {
            //  base[root] = 0;
            return 0;
        }
        if (base.find(root) != base.end())
        {
            return base[root];
        }

        int val = 0;
        if (root->left != NULL)
        {
            val += rob(root->left->left);
            val += rob(root->left->right);
        }
        if (root->right != NULL)
        {
            val += rob(root->right->left);
            val += rob(root->right->right);
        }

        return base[root] = max(root->val + val,
                                rob(root->left) + rob(root->right));
    }
};