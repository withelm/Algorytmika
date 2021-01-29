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
    ListNode *deleteNodes(ListNode *head, int m, int n)
    {
        ListNode *tmp = head;
        int save_m = m, save_n = n;

        while (tmp != NULL && m > 1)
        {
            --m;
            tmp = tmp->next;
        }
        if (m > 1)
            return head;
        if (tmp == NULL)
            return head;

        ListNode *tmp2 = tmp;
        while (tmp2 != NULL && n > -1)
        {
            --n;
            tmp2 = tmp2->next;
        }
        if (n > -1 || tmp2 == NULL)
        {
            tmp->next = NULL;
            return head;
        }

        tmp->next = deleteNodes(tmp2, save_m, save_n);
        return head;
    }
};