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
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        TreeNode *tmp = new TreeNode(*max_element(nums.begin(), nums.end()));

        vector<int> left, right;
        int index = 0;
        for (; index < nums.size() && nums[index] < tmp->val; index++)
        {
            left.push_back(nums[index]);
        }
        ++index;
        for (; index < nums.size(); ++index)
            right.push_back(nums[index]);
        tmp->left = constructMaximumBinaryTree(left);
        tmp->right = constructMaximumBinaryTree(right);
        return tmp;
    }
};