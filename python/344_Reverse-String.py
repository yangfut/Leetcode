class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        if len(s)==1: return
        ptr1, ptr2, tmp = 0, len(s)-1, 0

        while(ptr1<ptr2):
            
            if s[ptr1] != s[ptr2]:
                #swap
                tmp = s[ptr1]
                s[ptr1] = s[ptr2]
                s[ptr2] = tmp

            ptr1+=1
            ptr2-=1
        