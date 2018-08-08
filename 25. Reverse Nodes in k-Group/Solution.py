# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None or k <= 1:
            return head
        dummy = ListNode(0)
        dummy.next = head
        head = dummy
        while head.next is not None:
            head = self.reverseNextK(head, k)
        return dummy.next

    def reverseNextK(self, head, k):
        p = head
        for i in range(k):
            if p.next is None:
                return p
            p = p.next
        count = 0
        p = head.next.next
        tail = head.next
        while count < k - 1:
            temp = p.next
            tail.next = temp
            p.next = head.next
            head.next = p
            p = temp
            count += 1
        return tail
