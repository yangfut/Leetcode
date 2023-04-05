class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        st, ed = 0, len(nums)
        
        if ed == 1:
            return ed if target > nums[st] else st
        
        pivotIdx = (ed+st)//2
        pivot = nums[pivotIdx]
        while(pivot != target):
            
            if ed-st <= 1:
                return st if nums[st] > target else ed
            elif pivot > target:
                ed = pivotIdx
            else:
                st = pivotIdx

            pivotIdx = (ed+st)//2
            pivot = nums[pivotIdx]
        return pivotIdx
