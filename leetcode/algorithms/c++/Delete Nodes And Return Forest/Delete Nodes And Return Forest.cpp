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
    set<int> base;

    vector<TreeNode *> dfs(TreeNode *root)
    {
        vector<TreeNode *> result;
        if (root == NULL)
            return {};

        bool isFind = false;
        if (base.find(root->val) != base.end())
        {
            if (root->left != NULL && base.find(root->left->val) == base.end())
                result.push_back(root->left);
            if (root->right != NULL && base.find(root->right->val) == base.end())
                result.push_back(root->right);
            isFind = true;
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        for (auto &x : left)
        {
            result.push_back(x);
        }
        for (auto &x : right)
        {
            result.push_back(x);
        }
        if (root->left != NULL && base.find(root->left->val) != base.end())
        {
            root->left = NULL;
        }
        if (root->right != NULL && base.find(root->right->val) != base.end())
        {
            root->right = NULL;
        }
        if (base.find(root->val) != base.end())
        {
            root = NULL;
        }

        return result;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        for (auto &x : to_delete)
            base.insert(x);
        vector<TreeNode *> result = dfs(root);
        if (base.find(root->val) == base.end())
            result.insert(result.begin(), root);
        return result;
    }
};