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
    map<int, vector<int>> base;
    void dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return;
        base[deep].push_back(x->val);
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        dfs(root, 0);
        vector<double> r;
        for (auto &x : base)
        {
            double sum = 0;
            for (auto &i : x.second)
            {
                sum += i;
            }
            r.push_back(sum / x.second.size());
        }
        return r;
    }
};