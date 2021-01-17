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
    bool hasCycle(ListNode *head)
    {
        int LIMIT = 1e6;
        int i = 0;
        while (head != NULL && i < LIMIT)
        {
            head = head->next;
            ++i;
        }
        return head != NULL;
    }
};