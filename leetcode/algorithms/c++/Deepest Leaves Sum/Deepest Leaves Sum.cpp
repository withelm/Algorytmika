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
    int maxDeep = 0;

    void dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return;
        base[deep].push_back(x->val);
        maxDeep = max(maxDeep, deep);
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        int r = 0;
        for (auto &x : base[maxDeep])
            r += x;
        return r;
    }
};