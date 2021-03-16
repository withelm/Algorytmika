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
    TreeNode *str2tree(string s)
    {
        cout << s << endl;
        if (s.size() == 0)
            return NULL;
        int val = 0;
        bool isMinus = false;
        int index = 0;
        int n = s.size();
        if (s[index] == '-')
        {
            isMinus = true;
            ++index;
        }

        while (index < n && s[index] >= '0' && s[index] <= '9')
        {
            val = val * 10 + (s[index] - '0');
            ++index;
        }
        if (isMinus)
            val = -val;
        if (index == n)
            return new TreeNode(val);

        ++index;
        int leftIndex = index;
        int num = 1;
        while (num > 0)
        {
            if (s[index] == '(')
                ++num;
            if (s[index] == ')')
                --num;
            ++index;
        }

        auto left = s.substr(leftIndex, index - leftIndex - 1);
        string right = "";
        try
        {
            right = s.substr(index + 1, n - index - 2);
        }
        catch (...)
        {
        }
        return new TreeNode(val, str2tree(left), str2tree(right));
    }
};