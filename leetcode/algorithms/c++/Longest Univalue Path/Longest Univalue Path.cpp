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
    int r;
    int dfs(TreeNode *x)
    {
        if (x == NULL)
            return 0;

        int left = dfs(x->left);
        int right = dfs(x->right);

        int aLeft = 0, aRight = 0;
        if (x->left != NULL && x->left->val == x->val)
            aLeft += left + 1;
        if (x->right != NULL && x->right->val == x->val)
            aRight += right + 1;

        r = max(r, aLeft + aRight);

        return max(aLeft, aRight);
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        r = 0;
        if (root == NULL)
            return 0;
        dfs(root);
        return r;
    }
};