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
    vector<int> result;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        if (x->right == NULL && x->left != NULL)
            result.push_back(x->left->val);
        if (x->right != NULL && x->left == NULL)
            result.push_back(x->right->val);
        dfs(x->right);
        dfs(x->left);
    }

public:
    vector<int> getLonelyNodes(TreeNode *root)
    {
        dfs(root);
        return result;
    }
};