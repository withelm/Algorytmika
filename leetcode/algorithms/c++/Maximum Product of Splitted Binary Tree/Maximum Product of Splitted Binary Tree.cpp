/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  int MOD = 1e9 + 7;
  long long int result = -625000000000000000ll;
  int dfsSum(TreeNode *x) {
    if (x == NULL)
      return 0;
    x->val += dfsSum(x->left);
    x->val += dfsSum(x->right);
    return x->val;
  }

  void dfs(TreeNode *parent, TreeNode *x, int add) {
    if (x == NULL)
      return;
    long long int partSum = parent->val - x->val + add;
    result = max(result, partSum * x->val);
    dfs(x, x->left, partSum);
    dfs(x, x->right, partSum);
  }

public:
  int maxProduct(TreeNode *root) {
    if (root == NULL)
      return 0;
    dfsSum(root);
    dfs(root, root->right, 0);
    dfs(root, root->left, 0);
    return result % MOD;
  }
};