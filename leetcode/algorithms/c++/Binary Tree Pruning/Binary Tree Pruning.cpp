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
    bool clear(TreeNode* root, int lvl)
    {
        if (root == NULL)
            return true;
        
        bool left = true, right = true;
        if (left = clear(root->left, lvl + 1))
            root->left = NULL;
        if (right = clear(root->right, lvl + 1))
            root->right = NULL;
        //cout << left << " " << right << " " << lvl << endl;
        return root->val == 0 && left && right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (clear(root, 1))
            return NULL;
        return root;
    }
};