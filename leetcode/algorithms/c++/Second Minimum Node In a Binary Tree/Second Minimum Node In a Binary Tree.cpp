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
    set<int> b;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        b.insert(x->val);
        dfs(x->right);
        dfs(x->left);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root);
        if (b.size() == 1)
            return -1;
        int index = 0;
        for (auto &x : b)
        {
            if (index == 1)
                return x;
            ++index;
        }
        return -1;
    }
};