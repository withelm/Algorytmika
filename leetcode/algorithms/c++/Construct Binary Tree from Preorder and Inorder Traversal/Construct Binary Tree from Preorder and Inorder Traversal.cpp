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
    map<int, int> base;
    int pre = 0;
    TreeNode *betterBuild(vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return NULL;

        auto val = preorder[pre++];
        auto root = new TreeNode(val);
        auto sr = base[val];

        root->left = betterBuild(preorder, left, sr - 1);
        root->right = betterBuild(preorder, sr + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            base[inorder[i]] = i;
        }
        return betterBuild(preorder, 0, preorder.size() - 1);
    }
};