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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *root = head;
        vector<ListNode *> r;
        while (head != NULL)
        {
            if (head->val != val)
                r.push_back(head);
            head = head->next;
        }

        if (r.size() == 0)
            return NULL;
        root = r[0];
        for (int i = 1; i < r.size(); i++)
        {
            root->next = r[i];
            root = r[i];
        }
        root->next = NULL;
        return r[0];
    }
};