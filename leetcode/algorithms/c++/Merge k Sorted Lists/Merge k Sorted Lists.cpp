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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> vals;
        for (auto &x : lists)
        {
            auto root = x;
            while (root != NULL)
            {
                vals.push_back(root->val);
                root = root->next;
            }
        }
        if (vals.size() == 0)
            return NULL;
        ListNode *solve = new ListNode();
        ListNode *tmp = solve;
        sort(vals.begin(), vals.end());
        for (auto &x : vals)
        {
            tmp->next = new ListNode(x);
            tmp = tmp->next;
        }
        return solve->next;
    }
};