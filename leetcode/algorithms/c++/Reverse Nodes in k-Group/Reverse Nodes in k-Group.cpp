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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> t;
        while(head != NULL) {
            t.push_back(head);
            head = head->next;
        }
        
        int n = t.size();
        int index = 0;
        while(index + k <= n) {
            reverse(t.begin() + index, t.begin() + index + k);
            index += k;
        }
        for(int i = 0; i < n - 1; i++) {
            t[i]->next = t[i + 1];
        }
        t[n - 1]->next = NULL;
        return t[0];
    }
};