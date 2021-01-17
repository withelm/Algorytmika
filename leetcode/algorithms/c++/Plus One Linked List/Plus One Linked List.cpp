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
private:
    int k = 0;

public:
    ListNode *plusOne(ListNode *x)
    {
        ++k;
        if (x == NULL)
        {
            return NULL;
        }
        if (x->next == NULL)
        {
            x->val += 1;
        }
        else
        {
            plusOne(x->next);
        }
        if (x->next != NULL)
        {
            x->val += x->next->val / 10;
            x->next->val %= 10;
        }
        --k;

        if (k == 0 && x->val >= 10)
        {
            auto r = new ListNode(x->val / 10, x);
            x->val %= 10;
            return r;
        }

        return x;
    }
};