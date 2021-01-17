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
    vector<int> t;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        t.push_back(x->val);
        dfs(x->left);
        dfs(x->right);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);
        int n = t.size();
        int r = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                r = min(r, abs(t[i] - t[j]));
        return r;
    }
};