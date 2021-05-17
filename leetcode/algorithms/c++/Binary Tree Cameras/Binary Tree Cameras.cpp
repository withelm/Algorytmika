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
    int INF = 1e9;
    map<TreeNode *, vector<int>> dp;

    vector<int> dfs(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0, INF};
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        return dp[root] = {
                   left[1] + right[1],
                   min(left[2] + min(right[1], right[2]), right[2] + min(left[1], left[2])),
                   min(left[0], min(left[1], left[2])) + min(right[0], min(right[1], right[2])) + 1};
    }

public:
    int minCameraCover(TreeNode *root)
    {
        dfs(root);
        return min(dp[root][1], dp[root][2]);
    }
};