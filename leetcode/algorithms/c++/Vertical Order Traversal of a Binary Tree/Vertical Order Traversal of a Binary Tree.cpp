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
    map<int, vector<vector<int>>> base;
    void dfs(TreeNode *x, int i, int j)
    {
        if (x == NULL)
            return;
        base[i].push_back({j, x->val});
        dfs(x->left, i - 1, j - 1);
        dfs(x->right, i + 1, j - 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (auto &s : base)
        {
            sort(s.second.begin(), s.second.end(), [](const vector<int> &a, const vector<int> &b) {
                if (a[0] == b[0])
                    return a[1] < b[1];
                return a[0] > b[0];
            });
            vector<int> tmp;
            for (auto &i : s.second)
            {
                tmp.push_back(i[1]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};