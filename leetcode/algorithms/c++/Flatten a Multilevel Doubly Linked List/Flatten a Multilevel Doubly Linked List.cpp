/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
private:
    vector<Node *> order;
    void dfs(Node *x)
    {
        if (x == NULL)
            return;
        order.push_back(x);
        dfs(x->child);
        dfs(x->next);
        x->prev = NULL;
        x->next = NULL;
        x->child = NULL;
    }

public:
    Node *flatten(Node *head)
    {
        dfs(head);

        if (head == NULL)
            return NULL;

        for (int i = 1; i < order.size(); i++)
        {
            order[i - 1]->next = order[i];
            order[i]->prev = order[i - 1];
        }

        return order[0];
    }
};