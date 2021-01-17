/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public ListNode DeleteDuplicates(ListNode head)
    {
        ListNode result = head;
        var tab = GetVal(head);

        var result2 = tab.Distinct().ToList();

        if (result2.Count == 0) return null;
        if (result2.Count == 1)
        {
            return new ListNode(result2[0]);
        }

        ListNode r = new ListNode(result2[0]);
        ListNode rr = r;

        for (int i = 1; i < result2.Count; i++)
        {
            r.next = new ListNode(result2[i]);
            r = r.next;
        }
        return rr;


    }

    public List<int> GetVal(ListNode x)
    {
        List<int> r = new List<int>();

        while (x != null)
        {
            r.Add(x.val);
            x = x.next;
        }
        return r;
    }
}