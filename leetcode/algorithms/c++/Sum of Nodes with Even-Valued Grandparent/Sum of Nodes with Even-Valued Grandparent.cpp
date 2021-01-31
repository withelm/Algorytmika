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
public:
    int sumEvenGrandparent(TreeNode *x)
    {
        if (x == NULL)
            return 0;
        int r = 0;
        if (x->val % 2 == 0)
        {
            if (x->left != NULL)
            {
                if (x->left->left != NULL)
                    r += x->left->left->val;
                if (x->left->right != NULL)
                    r += x->left->right->val;
            }
            if (x->right != NULL)
            {
                if (x->right->left != NULL)
                    r += x->right->left->val;
                if (x->right->right != NULL)
                    r += x->right->right->val;
            }
        }
        return sumEvenGrandparent(x->left) + sumEvenGrandparent(x->right) + r;
    }
};