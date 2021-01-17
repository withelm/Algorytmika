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
    int INF = 1e9;
    int dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return INF;
        if (x->left == NULL && x->right == NULL)
            return deep;
        return min(dfs(x->left, deep + 1), dfs(x->right, deep + 1));
    }

public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return dfs(root, 0) + 1;
    }
};