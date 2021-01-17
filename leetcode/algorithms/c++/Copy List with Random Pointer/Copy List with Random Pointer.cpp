/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
private:
    map<Node *, Node *> base;

public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        if (base.find(head) != base.end())
            return base[head];

        Node *tmp = new Node(head->val);
        base[head] = tmp;
        tmp->next = copyRandomList(head->next);
        tmp->random = copyRandomList(head->random);

        return tmp;
    }
};