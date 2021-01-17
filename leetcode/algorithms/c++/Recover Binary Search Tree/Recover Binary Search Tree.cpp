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
    vector<TreeNode *> inorder;
    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        inorder.push_back(x);
        dfs(x->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        TreeNode *f1 = NULL, *f2 = NULL;
        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i]->val > inorder[i + 1]->val)
            {
                f1 = inorder[i + 1];
                if (f2 == NULL)
                    f2 = inorder[i];
                else
                    break;
            }
        }
        swap(f1->val, f2->val);
    }
};