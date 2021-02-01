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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        vector<ListNode *> t;
        while (head != NULL)
        {
            t.push_back(head);
            head = head->next;
        }
        int n = t.size();
        int mid = n / 2;
        TreeNode *result = new TreeNode(t[mid]->val);
        t[mid - 1]->next = NULL;
        result->left = sortedListToBST(t[0]);
        if (mid + 1 < n)
            result->right = sortedListToBST(t[mid + 1]);
        return result;
    }
};