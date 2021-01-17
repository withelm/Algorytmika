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


    public ListNode OddEvenList(ListNode head)
    {
        List<ListNode> a = new List<ListNode>();
        while (head != null)
        {
            a.Add(head);
            head = head.next;
        }
        int n = a.Count();

        if (n == 0) return null;
        if (n == 1) return a[0];

        for (int i = 2; i < n; i++)
        {
            a[i - 2].next = a[i];
            //  Console.WriteLine(string.Format("{0} -> {1}", i - 2, i));
        }

        if (n % 2 == 1)
        {
            a[n - 1].next = a[1];
            a[n - 2].next = null;
        }
        else
        {
            a[n - 1].next = null;
            a[n - 2].next = a[1];
        }




        return a[0];
    }
}