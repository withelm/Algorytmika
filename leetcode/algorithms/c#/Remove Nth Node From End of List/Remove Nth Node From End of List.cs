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
    private int m = 0;
    private int k = 0;

    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        if (head == null)
        {
            k = m - n;

            return null;
        }
        ++m;
        head.next = RemoveNthFromEnd(head.next, n);
        --m;
        if (m == k)
        {
            return head.next;
        }

        return head;
    }
}