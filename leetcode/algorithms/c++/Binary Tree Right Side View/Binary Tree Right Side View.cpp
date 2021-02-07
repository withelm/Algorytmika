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
    void dfs(TreeNode *x, int lvl)
    {
        if (x == NULL)
            return;
        base[lvl].push_back(x->val);
        dfs(x->right, lvl + 1);
        dfs(x->left, lvl + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        vector<int> r;
        for (auto &x : base)
        {
            r.push_back(x.second[0]);
        }
        return r;
    }
};