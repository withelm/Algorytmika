/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> base;
        while (head != NULL)
        {
            if (base.find(head) != base.end())
                return head;
            base.insert(head);
            head = head->next;
        }
        return NULL;
    }
};