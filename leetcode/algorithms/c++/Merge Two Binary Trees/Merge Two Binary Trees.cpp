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
    void dfs(TreeNode *x, TreeNode *y)
    {
        if (y == NULL)
            return;
        if (x == NULL && y == NULL)
            return;

        x->val += y->val;

        if (x->right == NULL && y->right != NULL)
        {
            x->right = y->right;
        }
        else
        {
            dfs(x->right, y->right);
        }
        if (x->left == NULL && y->left != NULL)
        {
            x->left = y->left;
        }
        else
        {
            dfs(x->left, y->left);
        }
    }

public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL)
            return t2;
        dfs(t1, t2);
        return t1;
    }
};