/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    TreeNode *dfs(TreeNode *x, int p, int q)
    {
        if (x == NULL)
            return NULL;

        if (x->val == p || x->val == q)
            return x;

        if (p < x->val && q < x->val)
        {
            return dfs(x->left, p, q);
        }
        else if (p > x->val && q > x->val)
        {
            return dfs(x->right, p, q);
        }
        else
        {
            return x;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        return dfs(root, p->val, q->val);
    }
};