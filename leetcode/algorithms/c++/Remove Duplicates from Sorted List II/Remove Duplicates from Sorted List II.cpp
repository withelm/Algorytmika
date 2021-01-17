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
    ListNode *deleteDuplicates(ListNode *head)
    {
        map<int, int> base;

        vector<int> vals;
        while (head != NULL)
        {
            ++base[head->val];
            vals.push_back(head->val);
            head = head->next;
        }

        vector<int> r;
        for (auto &x : vals)
            if (base[x] == 1)
                r.push_back(x);

        if (r.size() == 0)
            return NULL;
        ListNode *root = new ListNode(r[0]);
        ListNode *tmp = root;
        for (int i = 1; i < r.size(); i++)
        {
            tmp->next = new ListNode(r[i]);
            tmp = tmp->next;
        }
        return root;
    }
};