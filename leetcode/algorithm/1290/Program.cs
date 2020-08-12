using System;

namespace _1290
{

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public int GetDecimalValue(ListNode head)
        {
            if (head == null) return 0;
            int r = 0;

            while (head != null)
            {
                r *= 2;
                r += head.val;
                head = head.next;
            }
            return r;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
 
        }
    }
}
