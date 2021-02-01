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
    vector<TreeNode *> t;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        t.push_back(x);
        dfs(x->left);
        dfs(x->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root);
        root = t[0];
        for (int i = 1; i < t.size(); i++)
        {
            t[i - 1]->right = t[i];
            t[i - 1]->left = NULL;
        }
        t.back()->left = t.back()->right = NULL;
    }
};