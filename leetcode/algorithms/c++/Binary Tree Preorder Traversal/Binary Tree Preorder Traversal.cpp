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
    vector<int> t;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        t.push_back(x->val);
        dfs(x->left);
        dfs(x->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        dfs(root);
        return t;
    }
};