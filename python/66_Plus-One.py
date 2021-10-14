class Solution:
    def plusOne(self, digits):
        carry=1
        for i in range(-1, (len(digits)+1)*-1, -1):
            if carry == 0:
                break
            if digits[i] == 9:
                digits[i]=0
                carry = 1
                if i == len(digits)*-1:
                    digits.insert(0,carry)
            else:
                digits[i]+=carry
                carry=0
        return digits

S = Solution()
digits = [9]
print(S.plusOne(digits))
