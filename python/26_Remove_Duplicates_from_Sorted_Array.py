class Solution:
    def removeDuplicates(self, nums):
        if not nums: return 0
        ptr = 1
        bufferValue = nums[0]
        for value in nums[1:]:
            if bufferValue != value:
                nums[ptr], bufferValue = value, value
                ptr+=1
        return ptr


s = Solution()
#nums = [0,0,1,1,1,2,2,3,3,4]
#print(s.removeDuplicates(nums))

#nums = [1, 1, 2]
#print(s.removeDuplicates(nums))

nums = [1, 2, 3]
print(s.removeDuplicates(nums))

nums = []
print(s.removeDuplicates(nums))
