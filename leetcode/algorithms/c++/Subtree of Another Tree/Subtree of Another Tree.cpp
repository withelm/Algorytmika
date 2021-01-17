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
    vector<TreeNode *> toCheck;
    void dfs(TreeNode *x, int val)
    {
        if (x == NULL)
            return;
        if (x->val == val)
        {
            toCheck.push_back(x);
        }
        dfs(x->left, val);
        dfs(x->right, val);
    }
    bool dfs2(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL && r != NULL)
            return false;
        if (l != NULL && r == NULL)
            return false;
        if (l->val != r->val)
            return false;

        return dfs2(l->left, r->left) && dfs2(l->right, r->right);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (t == NULL)
            return true;
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL)
            return true;

        dfs(s, t->val);

        for (auto &x : toCheck)
        {
            if (dfs2(x, t))
                return true;
        }
        return false;
    }
};