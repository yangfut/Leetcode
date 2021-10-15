#Solution 2
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None: return head
        prev, ans = None, head
        
        while head:
            prev = head
            while head.next and head.val == head.next.val:
                head = head.next
            prev.next = head.next
            head = prev.next
        return ans
      
#Solution 1
#class Solution:
#    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
#        if head == None: return
#        Ans = ListNode(head.val, None)
#        pAns = Ans
#        cur = head
#        while(cur.next != None):
#            cur = cur.next            
#            if cur.val != pAns.val:
#                pAns.next = ListNode(cur.val, None)
#                pAns = pAns.next
#        return Ans
