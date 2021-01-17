/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *cheat;
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *x)
    {
        cheat = x;
        if (x == NULL)
            return "";
        string r = to_string(x->val);
        r += "{" + serialize(x->left) + "}";
        r += "{" + serialize(x->right) + "}";

        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        int val = 0;
        int index = 0;
        int n = data.size();
        bool isMinus = false;
        if (data[index] == '-')
        {
            isMinus = true;
            ++index;
        }
        while (data[index] != '{')
        {
            val *= 10;
            val += data[index] - '0';
            ++index;
        }
        if (isMinus)
            val *= -1;
        int sum = 1;
        ++index;
        string left = "";
        while (sum > 0)
        {
            if (data[index] == '{')
                ++sum;
            if (data[index] == '}')
                --sum;
            if (sum == 0)
                break;
            left += data[index];
            ++index;
        }
        string right = "";
        for (int i = index + 2; i < n - 1; i++)
        {
            right += data[i];
        }

        return new TreeNode(val, deserialize(left), deserialize(right));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));