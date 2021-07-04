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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        vector<ListNode *> t;
        while (head != NULL)
        {
            t.push_back(head);
            head = head->next;
        }
        reverse(t.begin() + left - 1, t.begin() + right);

        for (int i = 0; i < t.size() - 1; i++)
        {
            t[i]->next = t[i + 1];
        }
        t[t.size() - 1]->next = NULL;
        return t[0];
    }
};