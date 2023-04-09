class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #Time:O(n), Space:O(1)
        if (len(nums)==1):
            return

        ptr1, ptr2 = 0, 0
        while (ptr1<len(nums)):
            if nums[ptr1]==0:
                pass
            else:
                nums[ptr2] = nums[ptr1]
                ptr2+=1
            ptr1+=1
        
        for idx in range(ptr2, len(nums)):
            nums[idx]=0