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
    vector<TreeNode *> getLeaf(TreeNode *x)
    {
        if (x == NULL)
            return {};
        if (x->left == NULL && x->right == NULL)
            return {x};
        auto l = getLeaf(x->left);
        auto r = getLeaf(x->right);
        for (auto &i : r)
        {
            l.push_back(i);
        }
        return l;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        auto r1 = getLeaf(root1);
        auto r2 = getLeaf(root2);
        if (r1.size() != r2.size())
            return false;

        for (int i = 0; i < r1.size(); i++)
        {
            if (r1[i]->val != r2[i]->val)
                return false;
        }
        return true;
    }
};