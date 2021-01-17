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
    private int n;
    private static readonly Random random = new Random();
    List<ListNode> t = new List<ListNode>();
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head)
    {
        n = 0;
        while (head != null)
        {
            t.Add(head);
            head = head.next;
            ++n;
        }
    }

    /** Returns a random node's value. */
    public int GetRandom()
    {
        return t[random.Next() % n].val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.GetRandom();
 */