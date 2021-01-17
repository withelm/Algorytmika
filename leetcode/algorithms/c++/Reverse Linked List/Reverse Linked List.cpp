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
    ListNode *reverseList(ListNode *head)
    {
        vector<ListNode *> list;
        while (head != NULL)
        {
            list.push_back(head);
            head = head->next;
        }
        reverse(list.begin(), list.end());
        int n = list.size();

        if (n == 0)
            return head;

        ListNode *root = list[0];
        head = root;
        for (int i = 1; i < n; i++)
        {
            head->next = list[i];
            head = head->next;
        }
        head->next = NULL;
        return root;
    }
};