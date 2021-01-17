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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *x = head;
        vector<int> t;
        while (head != NULL)
        {
            t.push_back(head->val);
            head = head->next;
        }
        sort(t.begin(), t.end());
        head = x;
        for (auto &i : t)
        {
            x->val = i;
            x = x->next;
        }

        return head;
    }
};