# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        p = head
        carry = 0
        while (l1 != None or l2 != None):
            x1 = l1.val if l1 != None else 0
            x2 = l2.val if l2 != None else 0
            sum = x1 + x2 + carry
            carry = sum // 10
            n = sum % 10
            p.next = ListNode(n)
            p = p.next
            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next
        if carry > 0:
            p.next = ListNode(1)
        return head.next
