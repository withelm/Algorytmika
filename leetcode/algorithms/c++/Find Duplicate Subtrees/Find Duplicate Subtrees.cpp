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
    vector<TreeNode *> r;
    map<string, int> base;

    string dfs(TreeNode *x)
    {
        if (x == NULL)
            return "{}";
        string tmp = to_string(x->val) + "{" + dfs(x->left) + dfs(x->right) + "}";
        ++base[tmp];
        if (base[tmp] == 2)
            r.push_back(x);
        return tmp;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return r;
    }
};