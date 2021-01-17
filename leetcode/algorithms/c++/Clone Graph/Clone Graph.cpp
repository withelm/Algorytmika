/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
private:
    map<Node *, Node *> v;

public:
    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return NULL;
        if (v.find(node) != v.end())
            return v[node];

        Node *c = new Node(node->val);
        v[node] = c;
        for (auto x : node->neighbors)
        {
            auto i = cloneGraph(x);
            if (i != NULL)
                c->neighbors.push_back(i);
        }

        return c;
    }
};