/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution
{
    public ListNode DetectCycle(ListNode head)
    {
        Dictionary<ListNode, int> source = new Dictionary<ListNode, int>();
        while (head != null)
        {
            if (source.ContainsKey(head)) return head;
            source.Add(head, 0);
            head = head.next;
        }
        return null;

    }
}