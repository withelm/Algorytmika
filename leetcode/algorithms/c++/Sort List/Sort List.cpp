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
    ListNode *sortList(ListNode *head)
    {
        vector<int> t;
        while (head != NULL)
        {
            t.push_back(head->val);
            head = head->next;
        }
        sort(t.begin(), t.end());
        if (t.size() == 0)
            return NULL;
        ListNode *x, *y;
        y = new ListNode(t[0]);
        x = y;
        for (int i = 1; i < t.size(); i++)
        {
            y->next = new ListNode(t[i]);
            y = y->next;
        }
        return x;
    }
};