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
    map<int, int> b;
    map<int, vector<int>> r;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        ++b[x->val];
        dfs(x->left);
        dfs(x->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        dfs(root);
        int i = -1;
        int j = -1;

        for (auto &x : b)
        {
            r[x.second].push_back(x.first);
        }
        if (!r.empty())
            return (--r.end())->second;
        return {};
    }
};