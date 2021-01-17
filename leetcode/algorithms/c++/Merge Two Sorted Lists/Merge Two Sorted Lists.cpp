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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        vector<int> vals;
        while (l1 != NULL)
        {
            vals.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            vals.push_back(l2->val);
            l2 = l2->next;
        }
        sort(vals.begin(), vals.end());
        if (vals.size() == 0)
            return NULL;

        ListNode *root = new ListNode(vals[0]);
        ListNode *tmp = root;
        for (int i = 1; i < vals.size(); i++)
        {
            tmp->next = new ListNode(vals[i]);
            tmp = tmp->next;
        }
        return root;
    }
};