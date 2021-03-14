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
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> t;
        while (head != NULL)
        {
            t.push_back(head);
            head = head->next;
        }
        swap(t[k - 1], t[t.size() - k]);
        for (int i = 0; i < t.size(); i++)
        {
            cout << t[i]->val << endl;
            t[i]->next = i + 1 < t.size() ? t[i + 1] : NULL;
        }
        return t[0];
    }
};