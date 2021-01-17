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
    TreeNode *bst(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);

        TreeNode *tmp = new TreeNode();
        tmp->val = nums[(left + right) / 2];
        tmp->left = bst(nums, left, (left + right) / 2 - 1);
        tmp->right = bst(nums, (left + right) / 2 + 1, right);
        return tmp;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root;
        root = bst(nums, 0, nums.size() - 1);
        return root;
    }
};