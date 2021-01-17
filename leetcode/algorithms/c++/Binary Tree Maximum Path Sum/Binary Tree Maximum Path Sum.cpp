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
    int ans;
    int dfs(TreeNode *x)
    {
        if (x == NULL)
            return 0;
        auto left = dfs(x->left);
        auto right = dfs(x->right);

        if (x->left != NULL)
            ans = max(ans, left);
        if (x->right != NULL)
            ans = max(ans, right);
        ans = max(ans, left + right + x->val);
        ans = max(ans, left + x->val);
        ans = max(ans, right + x->val);

        return max(max(left, right) + x->val, x->val);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        ans = root->val;
        dfs(root);
        return ans;
    }
};