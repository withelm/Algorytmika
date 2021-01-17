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
    vector<int> r;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        r.push_back(x->val);
        dfs(x->right);
    }
    TreeNode *dfs2(int x)
    {
        if (x >= r.size())
            return NULL;
        return new TreeNode(r[x], NULL, dfs2(x + 1));
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        dfs(root);
        return dfs2(0);
    }
};