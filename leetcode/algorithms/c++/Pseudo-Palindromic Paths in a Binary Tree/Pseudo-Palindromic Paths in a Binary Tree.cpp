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
    int r;

    bool check(vector<int> &k)
    {
        int odd = 0;
        int even = 0;
        int sum = 0;
        for (auto &x : k)
        {
            if (x % 2 == 0)
                ++even;
            else
                ++odd;
            sum += x;
        }
        if (sum % 2 == 0)
            return odd == 0;
        return odd <= 1;
    }

    void dfs(TreeNode *x, vector<int> &k)
    {
        if (x == NULL)
            return;
        ++k[x->val];
        if (x->left == NULL && x->right == NULL)
        {
            r += check(k);
        }
        else
        {
            dfs(x->left, k);
            dfs(x->right, k);
        }
        --k[x->val];
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        r = 0;
        vector<int> k = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        dfs(root, k);
        return r;
    }
};