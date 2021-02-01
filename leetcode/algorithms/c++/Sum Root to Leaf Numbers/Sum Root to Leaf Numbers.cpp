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
    int result = 0;
    void dfs(TreeNode *x, int sum)
    {
        if (x == NULL)
            return;
        if (x->left == NULL && x->right == NULL)
            result += 10 * sum + x->val;
        dfs(x->left, 10 * sum + x->val);
        dfs(x->right, 10 * sum + x->val);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return result;
    }
};