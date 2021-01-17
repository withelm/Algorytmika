/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        vector<ListNode *> t;
        ListNode *head_t = head;
        while (head != NULL)
        {
            t.push_back(head);
            head = head->next;
        }

        k %= t.size();

        if (k == 0)
            return head_t;

        int i = t.size() - k;
        ListNode *root = t[i];
        ListNode *tmp = root;
        ++i;
        for (int j = 1; j < t.size(); j++)
        {
            tmp->next = t[i % t.size()];
            tmp = tmp->next;
            ++i;
        }
        tmp->next = NULL;
        return root;
    }
};