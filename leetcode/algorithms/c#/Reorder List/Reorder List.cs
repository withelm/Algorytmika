/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public void ReorderList(ListNode head)
    {

        List<ListNode> t = new List<ListNode>();
        ListNode root = head;
        while (head != null)
        {
            t.Add(head);
            head = head.next;
        }
        int n = t.Count;
        if (n == 0)
        {
            head = root;
            return;
        }
        List<ListNode> rs = new List<ListNode>(new ListNode[n]);

        for (int i = 0; i < n; i += 2)
        {
            rs[i] = t[i / 2];
        }
        int index = 1;
        for (int i = 1; i < n; i += 2)
        {
            rs[i] = t[n - index];
            ++index;
        }
        for (int i = 0; i < n - 1; i++)
        {
            rs[i].next = rs[i + 1];
        }
        rs[n - 1].next = null;
        head = rs[0];
    }
}