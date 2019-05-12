# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        current = ListNode(0)
        head = current
        carry = 0
        
        while l1 and l2:
            sum = l1.val + l2.val + carry
            carry = 1 if sum >= 10 else 0
            current.next = ListNode(sum % 10)
            current = current.next
            l1, l2 = l1.next, l2.next
        
        l = l1 if l1 else l2
        while l:
            sum = l.val + carry
            carry = 1 if sum >= 10 else 0
            current.next = ListNode(sum % 10)
            current = current.next
            l = l.next
        
        if carry:
            current.next = ListNode(1)
            
        return head.next
