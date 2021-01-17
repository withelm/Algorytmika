/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
private:
    map<int, vector<Node *>> base;
    void dfs(Node *x, int deep)
    {
        if (x == NULL)
            return;
        base[deep].push_back(x);
        dfs(x->left, deep + 1);
        dfs(x->right, deep + 1);
    }

public:
    Node *connect(Node *root)
    {
        dfs(root, 0);
        for (auto &x : base)
        {
            int n = x.second.size();
            for (int i = 1; i < n; i++)
            {
                x.second[i - 1]->next = x.second[i];
            }
        }
        return root;
    }
};