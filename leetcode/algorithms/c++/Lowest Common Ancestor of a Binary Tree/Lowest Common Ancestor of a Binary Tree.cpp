/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    vector<TreeNode *> getWay(TreeNode *x, TreeNode *y)
    {
        if (x == NULL)
            return {};
        if (x->val == y->val)
            return {y};
        auto left = getWay(x->left, y);
        if (left.size() > 0)
        {
            left.push_back(x);
            return left;
        }
        auto right = getWay(x->right, y);
        if (right.size() > 0)
        {
            right.push_back(x);
            return right;
        }
        return {};
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *u, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        auto uWay = getWay(root, u);
        auto qWay = getWay(root, q);
        reverse(uWay.begin(), uWay.end());
        reverse(qWay.begin(), qWay.end());

        if (uWay.size() > qWay.size())
            swap(uWay, qWay);

        int n = uWay.size();
        int i = 0;
        while (i < n && uWay[i]->val == qWay[i]->val)
        {
            ++i;
        }

        return uWay[i - 1];
    }
};