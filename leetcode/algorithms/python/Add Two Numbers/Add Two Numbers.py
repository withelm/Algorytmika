# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def getNumber(x: ListNode) -> str:
        if (x is None):
            return ""
        return str(x.val) + Solution.getNumber(x.next)

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        x, y = Solution.getNumber(l1), Solution.getNumber(l2)
        if (len(x) < len(y)):
            l1, l2 = l2, l1
        val = int(l1.val) + int(l2.val)
        begin = ListNode(val % 10)
        next = begin
        val = int(int(val) / int(10))
        while(l2.next is not None):
            l1 = l1.next
            l2 = l2.next
            val += int(l1.val) + int(l2.val)
            next.next = ListNode(val % 10)
            val = int(int(val) / int(10))
            next = next.next
        while(l1.next is not None):
            l1 = l1.next
            val += int(l1.val)
            next.next = ListNode(val % 10)
            val = int(int(val) / int(10))
            next = next.next
        if (val > 0):
            next.next = ListNode(val)
        return begin