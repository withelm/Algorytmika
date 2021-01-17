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
            return -2000;

        auto left = dfs(x->left);
        auto right = dfs(x->right);
        bool isOn = false;
        if ((x->left == NULL || (x->left != NULL && left == x->val)) &&
            (x->right == NULL || (x->right != NULL && right == x->val)))
        {
            ++r;
            isOn = true;
        }

        return isOn ? x->val : -2000;
    }

public:
    int countUnivalSubtrees(TreeNode *x)
    {
        if (x == NULL)
            return 0;
        r = 0;
        dfs(x);
        return r;
    }
};