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
    vector<TreeNode *> nodes;
    bool findNodes(TreeNode *r)
    {
        if (r == NULL)
            return false;
        if (r->left == NULL && r->right == NULL)
        {
            nodes.push_back(r);
            return true;
        }
        if (findNodes(r->left))
        {
            r->left = NULL;
        }
        if (findNodes(r->right))
        {
            r->right = NULL;
        }
        return false;
    }

public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        if (findNodes(root))
            root = NULL;
        vector<vector<int>> res;
        while (nodes.size() > 0)
        {
            vector<int> tmp;
            for (auto &item : nodes)
            {
                tmp.push_back(item->val);
            }
            res.push_back(tmp);
            nodes.clear();
            if (findNodes(root))
                root = NULL;
        }
        return res;
    }
};