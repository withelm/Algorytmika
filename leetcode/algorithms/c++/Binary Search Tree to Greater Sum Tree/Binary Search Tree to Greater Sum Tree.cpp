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
    TreeNode *bstToGst(TreeNode *root)
    {
        dfs(root);
        sort(t.begin(), t.end(), [](const TreeNode *a, const TreeNode *b) {
            return a->val > b->val;
        });
        int sum = 0;
        for (auto &x : t)
        {
            sum += x->val;
            x->val = sum;
        }
        return root;
    }
};