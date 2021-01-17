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
    int dfs(TreeNode *root, int x)
    {
        if (root == NULL)
        {
            return 0;
        }

        x *= 2;
        x += root->val;

        if (root->right == NULL && root->left == NULL)
        {
            return x;
        }

        return dfs(root->left, x) + dfs(root->right, x);
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
};