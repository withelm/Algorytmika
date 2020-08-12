using System;

namespace _2
{


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {

            string x = GetNumber(l1);
            string y = GetNumber(l2);

            if (x.Length < y.Length)
            {
                ListNode tmp = l1;
                l1 = l2;
                l2 = tmp;
            }

            int val = l1.val + l2.val;

            ListNode begin = new ListNode(val % 10);
            ListNode next = begin;
            val /= 10;

            while (l2.next != null)
            {
                l1 = l1.next;
                l2 = l2.next;
                val += l1.val + l2.val;
                next.next = new ListNode(val % 10);
                val /= 10;
                next = next.next;
            }
            while (l1.next != null)
            {
                l1 = l1.next;
                val += l1.val;
                next.next = new ListNode(val % 10);
                val /= 10;
                next = next.next;
            }

            if (val > 0)
            {
                next.next = new ListNode(val);
            }



            return begin;

        }

        private string GetNumber(ListNode x)
        {
            if (x == null) return string.Empty;
            return x.val.ToString() + GetNumber(x.next);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
