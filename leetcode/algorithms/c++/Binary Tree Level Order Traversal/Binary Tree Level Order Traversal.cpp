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
    map<int, vector<int>> base;
    void dfs(TreeNode *x, int k)
    {
        if (x == NULL)
            return;
        base[k].push_back(x->val);
        dfs(x->left, k + 1);
        dfs(x->right, k + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> r;
        dfs(root, 0);
        for (auto &x : base)
            r.push_back(x.second);
        return r;
    }
};