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
    vector<int> res;
    vector<int> error = {-1};
    int index = 0;
    bool dfs(TreeNode *x, vector<int> &t)
    {
        if (x == NULL)
            return true;
        if (x->val != t[index++])
            return false;

        auto left = x->left;
        auto right = x->right;

        if (left != NULL && left->val != t[index])
        {
            res.push_back(x->val);
            swap(left, right);
        }

        return dfs(left, t) && dfs(right, t);
    }

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        return dfs(root, voyage) ? res : error;
    }
};