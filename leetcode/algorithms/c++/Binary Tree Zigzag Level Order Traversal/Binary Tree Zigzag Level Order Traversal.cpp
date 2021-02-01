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
    void dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return;
        base[deep].push_back(x->val);
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        dfs(root, 0);
        vector<vector<int>> r;
        int cnt = 0;
        for (auto &x : base)
        {
            if (cnt % 2 == 1)
                reverse(x.second.begin(), x.second.end());
            r.push_back(x.second);
            ++cnt;
        }
        return r;
    }
};