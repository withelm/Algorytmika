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
    vector<int> in;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        in.push_back(x->val);
        dfs(x->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return in;
    }
};