# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode):
        list1 = []
        list2 = []
        
        while l1:
            list1.append(l1.val)
            l1 = l1.next
        while l2:
            list2.append(l2.val)
            l2 = l2.next
        sum_num, carry = 0, 0
        
        tmpNode = ListNode(0)
        while list1 or list2:
            n1 = list1.pop() if list1 else 0
            n2 = list2.pop() if list2 else 0
            
            sum_num = n1+n2+carry
            digit = sum_num % 10
            carry = sum_num // 10
            
            tmpNode.val = digit
            head = ListNode(carry)
            head.next = tmpNode
            tmpNode = head
            
        return head if head.val != 0 else head.next
        


def main():
    sol = Solution()
    
    list1 = [7,2,4,3]
    list2 = [5,6,4]
    
    l1 = ListNode(list1[0])
    ptr = l1
    
    for val in list1[1:]:
        tmpNode = ListNode()
        tmpNode.val = val
        ptr.next = tmpNode
        ptr = ptr.next
        
    l2 = ListNode(list2[0])
    ptr = l2
    
    for val in list2[1:]:
        tmpNode = ListNode()
        tmpNode.val = val
        ptr.next = tmpNode
        ptr = ptr.next
    
    ptr = l1
    print('Input: ')
    while ptr:
        print(ptr.val, end=' ')
        ptr = ptr.next
    print('')
    ptr = l2
    while ptr:
        print(ptr.val, end=' ')
        ptr = ptr.next
    
    ansNode = sol.addTwoNumbers(l1, l2)
    print('\nOutput: ')
    while ansNode:
        print(ansNode.val, end=' ')
        ansNode = ansNode.next
    

    
if __name__ == '__main__':
    main()


