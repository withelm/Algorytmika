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
    bool result;
    bool stop;
    int dfs(TreeNode *x, int deep)
    {
        if (stop)
            return -1;
        if (x == NULL)
            return deep;
        int left = dfs(x->left, deep + 1);
        int right = dfs(x->right, deep + 1);
        if (abs(left - right) > 1)
        {
            result = false;
            stop = true;
        }
        return max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {

        if (root == NULL)
            return true;
        result = true;
        stop = false;
        dfs(root, 1);

        return result;
    }
};