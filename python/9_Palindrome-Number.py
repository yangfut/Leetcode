class Solution:
    def isPalindrome(self, x: int) -> bool:
        def tolist(x):
            ret = []
            while (x>0):
                red = x % 10
                ret.append(red)
                x = x // 10
            if x<0:ret.append("-")
            return ret
        if x<0: return False
        myList = tolist(x)
        Length = len(myList)
        ptr0 = 0
        ptr1 = Length - 1
        while(ptr1 >= ptr0):
            if(myList[ptr0] == myList[ptr1]):
                ptr0 += 1
                ptr1 -= 1
            else:
                return False
        return True
