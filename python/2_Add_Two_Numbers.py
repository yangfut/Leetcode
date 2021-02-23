# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        ptr = head
        carry = 0
        
        while l1 or l2:
            if l1:
                n1 = l1.val
                l1 = l1.next
            else:
                n1 = 0
            
            if l2:
                n2 = l2.val
                l2 = l2.next
            else:
                n2 = 0
        
            tmpNode = ListNode((n1+n2+carry) % 10)
            carry = (n1+n2+carry) // 10
            ptr.next = tmpNode
            ptr = ptr.next
        
        if carry != 0:
            tmpNode = ListNode(carry)
            ptr.next = tmpNode
        
        return head.next
            
            
        
