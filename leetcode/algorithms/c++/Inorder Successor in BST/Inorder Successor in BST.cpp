/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        dfs(root);
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i]->val == p->val)
            {
                if (i + 1 < inorder.size())
                    return inorder[i + 1];
                return NULL;
            }
        }
        return NULL;
    }
};