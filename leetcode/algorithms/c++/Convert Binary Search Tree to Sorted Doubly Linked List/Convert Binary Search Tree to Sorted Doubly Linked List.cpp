/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
private:
    vector<int> t;
    void dfs(Node *x)
    {
        if (x == NULL)
            return;
        t.push_back(x->val);
        dfs(x->left);
        dfs(x->right);
    }

public:
    Node *treeToDoublyList(Node *root)
    {
        dfs(root);
        sort(t.begin(), t.end());

        if (t.size() == 0)
            return NULL;

        Node *r = new Node(t[0]);
        Node *last = r;
        for (int i = 1; i < t.size(); i++)
        {
            Node *tmp = new Node(t[i]);
            last->right = tmp;
            tmp->left = last;
            last = tmp;
        }
        last->right = r;
        r->left = last;

        return r;
    }
};