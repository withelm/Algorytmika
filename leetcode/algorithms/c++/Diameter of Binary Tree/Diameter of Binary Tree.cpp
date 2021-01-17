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
    int dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return deep;
        return max(dfs(x->right, deep + 1), dfs(x->left, deep + 1));
    }
    int dfs_main(TreeNode *x)
    {
        if (x == NULL)
            return 0;

        int right = dfs(x->right, 0);
        int left = dfs(x->left, 0);

        return max(right + left, max(
                                     dfs_main(x->left), dfs_main(x->right)));

        //return max(dfs_main(x->left), dfs_main(x->right));
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return dfs_main(root);
    }
};