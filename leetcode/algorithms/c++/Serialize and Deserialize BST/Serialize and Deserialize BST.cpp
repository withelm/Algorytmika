/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string result = to_string(root->val) + " ";
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    TreeNode *root = NULL;
    void addToTree(TreeNode *x, int v)
    {

        if (x == NULL)
        {
            root = new TreeNode(v);
            return;
        }
        TreeNode *last = x;
        while (x != NULL)
        {
            last = x;
            if (x->val > v)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        if (last->val > v)
        {
            last->left = new TreeNode(v);
        }
        else
        {
            last->right = new TreeNode(v);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return NULL;
        int index = 0;
        int num = 0;

        while (index < data.size())
        {
            if (data[index] >= '0' && data[index] <= '9')
            {
                num *= 10;
                num += data[index] - '0';
                ++index;
                continue;
            }
            if (data[index] == ' ')
            {
                addToTree(root, num);
                num = 0;
                ++index;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;