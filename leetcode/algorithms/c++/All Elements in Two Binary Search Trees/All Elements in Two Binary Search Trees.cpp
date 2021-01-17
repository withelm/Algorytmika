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
    vector<int> r;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        r.push_back(x->val);
        dfs(x->right);
        dfs(x->left);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        dfs(root1);
        dfs(root2);
        sort(r.begin(), r.end());
        return r;
    }
};