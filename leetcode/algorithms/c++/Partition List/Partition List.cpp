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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode();
        ListNode *big = new ListNode();
        ListNode *smallPointer = small;
        ListNode *bigPointer = big;
        while (head != NULL)
        {
            if (head->val < x)
            {
                smallPointer->next = new ListNode(head->val);
                smallPointer = smallPointer->next;
            }
            else
            {
                bigPointer->next = new ListNode(head->val);
                bigPointer = bigPointer->next;
            }
            head = head->next;
        }
        smallPointer->next = big->next;
        if (small->next == NULL)
            return big->next;
        return small->next;
    }
};