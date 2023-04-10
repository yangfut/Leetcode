class Solution:
    def reverseWords(self, s: str) -> str:
        
        if len(s)==1: return s
        s+=" "
        firstWord = 0
        left, right = 0, 0
        ans_arr = []
        while right < len(s):

            if s[right] == " ":
                if firstWord == 0:
                    word = s[left:right]
                    firstWord = 1
                else:
                    word = s[left:right+1]
                ans_arr.append(word[::-1])
                right += 1
                left = right
            else:
                right += 1

        return "".join(ans_arr)