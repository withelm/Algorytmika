#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

private:
    int dfs(TreeNode *x, int l, int r) 
    {
        if (x == nullptr)
            return 0;
        if (x->val >= l && x->val <= r) 
            return x->val + dfs(x->right, l, r) + dfs(x->left, l, r);
        return dfs(x->right, l, r) + dfs(x->left, l, r);
    }

public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        
    }
};

int main()
{
}