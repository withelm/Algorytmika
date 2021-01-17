/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        if (head == NULL)
        {
            Node *tmp = new Node(insertVal);
            tmp->next = tmp;
            return tmp;
        }
        if (head == head->next)
        {
            Node *tmp = new Node(insertVal, head);
            head->next = tmp;
            return tmp;
        }
        Node *root = head;
        set<Node *> base;
        bool isError = false;
        int val_max = -1;
        Node *node_max = NULL;
        while (!(head->val <= insertVal && head->next->val >= insertVal))
        {
            if (val_max <= head->val)
            {
                val_max = head->val;
                node_max = head;
            }

            if (base.find(head) == base.end())
            {
                base.insert(head);
            }
            else
            {
                isError = true;
                break;
            }
            head = head->next;
        }
        if (!isError)
        {
            Node *tmp = new Node(insertVal, head->next);
            head->next = tmp;
        }
        else
        {
            Node *tmp = new Node(insertVal, node_max->next);
            node_max->next = tmp;
        }

        return root;
    }
};