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
    vector<int> getNumber(ListNode *x)
    {
        vector<int> r;
        while (x != NULL)
        {
            r.push_back(x->val);
            x = x->next;
        }
        reverse(r.begin(), r.end());
        return r;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto v1 = getNumber(l1);
        auto v2 = getNumber(l2);

        if (v1.size() < v2.size())
            swap(v1, v2);

        vector<int> r;
        int tmp = 0;
        for (int i = 0; i < v2.size(); i++)
        {
            tmp = tmp + v1[i] + v2[i];
            r.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = v2.size(); i < v1.size(); i++)
        {
            tmp = tmp + v1[i];
            r.push_back(tmp % 10);
            tmp /= 10;
        }
        while (tmp > 0)
        {
            r.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(r.begin(), r.end());
        ListNode *rr = new ListNode();
        ListNode *ans = rr;
        for (auto &x : r)
        {

            rr->next = new ListNode(x);
            rr = rr->next;
        }
        return ans->next;
    }
};