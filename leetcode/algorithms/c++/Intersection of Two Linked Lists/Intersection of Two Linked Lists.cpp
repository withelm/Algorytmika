/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
private:
    set<ListNode *> v;

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (headA != NULL)
        {
            v.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            auto finder = v.find(headB);
            if (finder != v.end())
                return *finder;
            headB = headB->next;
        }
        return NULL;
    }
};