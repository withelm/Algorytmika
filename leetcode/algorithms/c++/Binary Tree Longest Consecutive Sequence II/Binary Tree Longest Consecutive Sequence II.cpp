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
class Solution {
private:
    int result = 0;
    
    
    
    vector<int> dfs(TreeNode* x, TreeNode* p)
    {
        
      if (x == NULL)
          return {0, 0};
        auto left = dfs(x->left, x);
        auto right = dfs(x->right, x);
        
        result = max(result, left[0] + right[1] + 1);
        result = max(result, left[1] + right[0] + 1);
        
        vector<int> r = {0, 0};
        if (x->val == p->val + 1)
            r[0] = max(left[0] , right[0]) + 1;
        if (x->val == p->val - 1)
            r[1] = max(left[1] , right[1]) + 1;
        return r;
    }
  
    
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root, root);
        
        return result;
    }
};