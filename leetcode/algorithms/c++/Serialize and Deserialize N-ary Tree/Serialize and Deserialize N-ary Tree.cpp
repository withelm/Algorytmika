/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *x)
    {
        if (x == NULL)
            return "";
        string r = to_string(x->val);
        for (auto &i : x->children)
        {
            r += "{" + serialize(i) + "}";
        }
        return r;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {

        if (data.size() == 0)
            return NULL;
        int val = 0;
        int index = 0;
        int n = data.size();
        while (data[index] != '{' && index < n)
        {
            val *= 10;
            val += data[index] - '0';
            ++index;
        }
        int sum = 1;
        ++index;
        vector<Node *> child;
        int start = index;
        for (; index < n; index++)
        {
            if (sum == 0)
            {
                child.push_back(deserialize(data.substr(start, index - start - 1)));
                start = index + 1;
                while (index < n && data[index] != '{')
                    ++index;
                sum = 1;
            }
            else
            {
                if (data[index] == '{')
                    ++sum;
                if (data[index] == '}')
                    --sum;
            }
        }
        if (n - start - 1 >= 0)
            child.push_back(deserialize(data.substr(start, n - start - 1)));

        return new Node(val, child);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));