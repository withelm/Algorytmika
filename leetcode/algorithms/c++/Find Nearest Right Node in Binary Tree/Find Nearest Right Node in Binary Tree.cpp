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
    map<int, vector<TreeNode *>> base;
    map<TreeNode *, int> lvl;
    void dfs(TreeNode *x, int deep)
    {
        if (x == NULL)
            return;
        base[deep].push_back(x);
        lvl[x] = deep;
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u)
    {
        dfs(root, 0);

        auto row = base[lvl[u]];
        int n = row.size();
        for (int i = 0; i < n; i++)
        {
            if (row[i]->val == u->val)
            {
                if (i + 1 < n)
                    return row[i + 1];
                return NULL;
            }
        }
        return NULL;
    }
};