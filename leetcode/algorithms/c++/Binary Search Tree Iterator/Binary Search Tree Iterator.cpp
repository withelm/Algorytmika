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
class BSTIterator
{
private:
    vector<TreeNode *> t;
    int index = 0;
    int n = 0;

    void dfs(TreeNode *x)
    {
        if (x == NULL)
            return;
        dfs(x->left);
        t.push_back(x);
        dfs(x->right);

        ++n;
    }

public:
    BSTIterator(TreeNode *root)
    {
        dfs(root);
    }

    int next()
    {
        return t[index++]->val;
    }

    bool hasNext()
    {
        return index < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */