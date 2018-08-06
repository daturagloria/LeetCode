class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        p1, p2 = dummy, dummy
        while n:
            p2 = p2.next
            n -= 1
        while p2.next:
            p1 = p1.next
            p2 = p2.next
        p1.next = p1.next.next
        return dummy.next