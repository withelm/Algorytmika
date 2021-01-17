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

const static int MAX = 1e5;
const static int LOG = 10;

class Solution
{
private:
    int p[LOG][MAX], pre[MAX], treeSize[MAX];
    bool vis[MAX];
    int cnt = 0;
    map<int, vector<int>> base;

    bool isChild(int u, int v)
    {
        return pre[u] >= pre[v] && pre[u] < pre[v] + treeSize[v];
    }

    int lca(int u, int v)
    {
        if (isChild(u, v))
            return v;
        if (isChild(v, u))
            return u;

        int i = u, j = LOG - 1;
        while (j >= 0)
        {
            if (isChild(v, p[j][i]))
                --j;
            else
                i = p[j][i];
        }
        return p[0][i];
    }

    void dfs(TreeNode *v, int deep)
    {
        if (v == NULL)
            return;
        base[deep].push_back(v->val);
        pre[v->val] = ++cnt;
        if (v->left != NULL)
        {
            int i = v->left->val;
            if (!vis[i])
            {
                p[0][i] = v->val;
                vis[i] = true;
                dfs(v->left, deep + 1);
            }
        }
        if (v->right != NULL)
        {
            int i = v->right->val;
            if (!vis[i])
            {
                p[0][i] = v->val;
                vis[i] = true;
                dfs(v->right, deep + 1);
            }
        }
        treeSize[v->val] = cnt + 1 - pre[v->val];
    }
    TreeNode *find(TreeNode *x, int v)
    {
        if (x == NULL)
            return NULL;
        if (x->val == v)
            return x;
        auto left = find(x->left, v);
        if (left != NULL)
            return left;
        return find(x->right, v);
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        for (int i = 0; i < MAX; i++)
        {
            pre[i] = 0;
            treeSize[i] = 0;
            vis[i] = false;
        }
        for (int i = 0; i < LOG; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                p[i][j] = 0;
            }
        }
        vis[root->val] = true;
        dfs(root, 1);
        p[0][root->val] = root->val;
        for (int i = 1; i < LOG; i++)
        {
            for (int j = 1; j < MAX; j++)
            {
                p[i][j] = p[i - 1][p[i - 1][j]];
            }
        }

        auto last = base.rbegin()->second;
        int ans = last[0];
        for (auto &i : last)
        {
            ans = lca(ans, i);
        }
        return find(root, ans);
    }
};