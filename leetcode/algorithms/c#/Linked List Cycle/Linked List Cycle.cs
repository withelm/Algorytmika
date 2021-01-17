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
    public bool HasCycle(ListNode head)
    {

        ListNode slow = head;
        ListNode fast = head;
        while (slow != null && slow.next != null && fast != null && fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            //Console.WriteLine(string.Format("{0}, {1}", slow.val, fast.val));
            if (slow == fast)
                return true;

        }
        return false;
    }
}