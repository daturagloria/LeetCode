# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def swapPairs(self, linklist):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        head.next = linklist
        p = head
        while p.next is not None:
            temp = p.next.next
            if temp is None:
                return head.next
            p.next.next = temp.next
            temp.next = p.next
            p.next = temp
            p = temp.next
        return head.next
