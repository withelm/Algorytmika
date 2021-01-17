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
    vector<string> r;
    void dfs(TreeNode *x, string v)
    {
        if (x == NULL)
        {
            return;
        }

        string tmp = "->" + to_string(x->val);
        v += tmp;
        dfs(x->left, v);
        dfs(x->right, v);

        if (x->left == NULL && x->right == NULL)
        {
            r.push_back(v);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL)
            return {to_string(root->val)};

        dfs(root->left, to_string(root->val));
        dfs(root->right, to_string(root->val));

        return r;
    }
};