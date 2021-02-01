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
    vector<vector<int>> result;

    void dfs(TreeNode *x, vector<int> &way, int sum, int targetSum)
    {
        if (x == NULL)
            return;
        if (x->left == NULL && x->right == NULL && x->val + sum == targetSum)
        {
            way.push_back(x->val);
            result.push_back(way);
            way.pop_back();
            return;
        }

        way.push_back(x->val);
        dfs(x->left, way, sum + x->val, targetSum);
        dfs(x->right, way, sum + x->val, targetSum);
        way.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return result;
        vector<int> start = {};
        dfs(root, start, 0, targetSum);
        return result;
    }
};