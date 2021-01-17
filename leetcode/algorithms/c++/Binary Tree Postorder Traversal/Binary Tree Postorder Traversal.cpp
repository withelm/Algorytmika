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

        dfs(x->left);
        dfs(x->right);
        t.push_back(x->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        dfs(root);
        return t;
    }
};