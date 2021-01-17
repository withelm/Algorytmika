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
    map<TreeNode *, int> base;
    TreeNode *findNode(TreeNode *x, int v, int deep)
    {
        if (x == NULL)
            return NULL;
        base[x] = deep;
        if (x->left != NULL && x->left->val == v)
            return x;
        if (x->right != NULL && x->right->val == v)
            return x;
        auto left = findNode(x->left, v, deep + 1);
        if (left != NULL)
            return left;
        return findNode(x->right, v, deep + 1);
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        auto xNode = findNode(root, x, 0);
        auto yNode = findNode(root, y, 0);
        if (xNode == NULL && yNode == NULL)
            return true;
        if (xNode == NULL && yNode != NULL)
            return false;
        if (xNode != NULL && yNode == NULL)
            return false;
        return xNode->val != yNode->val && base[xNode] == base[yNode];
    }
};