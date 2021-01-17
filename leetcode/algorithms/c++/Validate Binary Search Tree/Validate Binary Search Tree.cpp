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
    vector<int> t;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        t.push_back(x->val);
        dfs(x->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        dfs(root);
        for (int i = 0; i + 1 < t.size(); i++)
        {
            if (t[i] >= t[i + 1])
                return false;
        }
        return true;
    }
};