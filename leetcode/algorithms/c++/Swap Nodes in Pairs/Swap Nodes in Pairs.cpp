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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        vector<ListNode *> r;

        while (head != NULL)
        {
            r.push_back(head);
            head = head->next;
        }
        int n = r.size();

        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 < n)
                swap(r[i], r[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
                r[i]->next = r[i + 1];
            else
                r[i]->next = NULL;
        }
        return r[0];
    }
};