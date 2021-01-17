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
    vector<TreeNode *> gt(int s, int e)
    {
        vector<TreeNode *> result;
        if (s > e)
        {
            result.push_back(NULL);
            return result;
        }
        for (int i = s; i <= e; i++)
        {
            auto left = gt(s, i - 1);
            auto right = gt(i + 1, e);
            for (auto &l : left)
            {
                for (auto &r : right)
                {
                    TreeNode *ct = new TreeNode(i);
                    ct->right = r;
                    ct->left = l;
                    result.push_back(ct);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return gt(1, n);
    }
};