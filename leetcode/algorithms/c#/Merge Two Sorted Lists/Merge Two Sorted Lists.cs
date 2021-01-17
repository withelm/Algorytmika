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
    public ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        if (l1 == null && l2 == null) return null;

        List<int> l1List = GetList(l1);
        List<int> l2List = GetList(l2);

        List<int> sum = new List<int>();
        sum.AddRange(l1List);
        sum.AddRange(l2List);
        sum.Sort();

        ListNode begin = new ListNode(sum[0]);
        ListNode next = begin;
        for (int i = 1; i < sum.Count; i++)
        {
            next.next = new ListNode(sum[i]);
            next = next.next;
        }
        return begin;


    }

    public List<int> GetList(ListNode x)
    {
        List<int> result = new List<int>();
        while (x != null)
        {
            result.Add(x.val);
            x = x.next;
        }
        return result;
    }
}