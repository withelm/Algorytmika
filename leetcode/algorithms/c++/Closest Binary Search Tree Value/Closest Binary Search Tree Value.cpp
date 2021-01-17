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
    void dfs(TreeNode *x, double t)
    {
        if (x == NULL)
            return;

        if (abs(ans - t) > abs(x->val - t))
        {
            ans = x->val;
        }
        dfs(x->left, t);
        dfs(x->right, t);
    }

public:
    int closestValue(TreeNode *root, double target)
    {
        ans = root->val;
        dfs(root, target);
        return ans;
    }
};