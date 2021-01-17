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

class Trie
{
public:
    Trie *left, *right;
    int minVal, maxVal;
};

class Solution
{
private:
    int result = 0;
    Trie *dfs(TreeNode *x)
    {
        if (x == NULL)
            return NULL;
        Trie *r = new Trie();
        r->minVal = x->val;
        r->maxVal = x->val;
        r->left = dfs(x->left);
        r->right = dfs(x->right);
        if (r->left != NULL)
        {
            r->minVal = min(r->minVal, r->left->minVal);
            r->maxVal = max(r->maxVal, r->left->maxVal);
        }
        if (r->right != NULL)
        {
            r->minVal = min(r->minVal, r->right->minVal);
            r->maxVal = max(r->maxVal, r->right->maxVal);
        }
        result = max(result, abs(x->val - r->minVal));
        result = max(result, abs(x->val - r->maxVal));
        return r;
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        Trie *r = dfs(root);
        return result;
    }
};