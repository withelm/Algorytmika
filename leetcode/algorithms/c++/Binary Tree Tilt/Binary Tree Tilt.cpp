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
    int result = 0;
    int sum(TreeNode *x)
    {
        if (x == NULL)
            return 0;
        x->val += sum(x->left) + sum(x->right);
        return x->val;
    }
    int abss(TreeNode *x)
    {
        if (x == NULL)
            return 0;
        result += abs(abss(x->left) - abss(x->right));
        return x->val;
    }

public:
    int findTilt(TreeNode *root)
    {
        sum(root);
        abss(root);
        return result;
    }
};