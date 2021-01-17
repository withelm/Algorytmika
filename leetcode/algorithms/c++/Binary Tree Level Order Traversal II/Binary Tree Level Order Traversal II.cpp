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
    vector<vector<int>> r;
    void dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return;
        if (r.size() == deep)
            r.push_back({});
        r[deep].push_back(x->val);
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        dfs(root, 0);
        reverse(r.begin(), r.end());
        return r;
    }
};