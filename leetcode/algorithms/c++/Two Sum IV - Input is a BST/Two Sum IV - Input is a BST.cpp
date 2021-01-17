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
    map<int, int> base;

    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        ++base[x->val];
        dfs(x->left);
        dfs(x->right);
    }

    bool check(TreeNode *x, int k)
    {
        if (x == NULL)
            return false;
        int curr = k - x->val;
        if (x->val != curr && base[curr] > 0)
        {
            return true;
        }
        if (x->val == curr && base[curr] > 1)
        {
            return true;
        }
        return check(x->left, k) || check(x->right, k);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        dfs(root);
        return check(root, k);
    }
};