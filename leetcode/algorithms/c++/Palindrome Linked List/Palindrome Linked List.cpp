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
    bool isPalindrome(ListNode *head)
    {
        vector<int> list1;
        vector<int> list2;
        while (head != NULL)
        {
            list1.push_back(head->val);
            list2.push_back(head->val);
            head = head->next;
        }
        reverse(list2.begin(), list2.end());
        for (int i = 0; i < list1.size(); i++)
        {
            if (list1[i] != list2[i])
                return false;
        }
        return true;
    }
};