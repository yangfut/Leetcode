class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        st, ed = 0, len(nums)
        if ed == 1:
            return st if nums[st] == target else -1

        pivotIdx = ed/2
        pivot = nums[pivotIdx]

        while(pivot!=target):
            if ed - st <= 1:
                return  st if nums[st] == target else -1
            elif pivot > target:
                ed = pivotIdx
            else:
                st = pivotIdx
            
            pivotIdx = (st+ed)/2
            pivot = nums[pivotIdx]
        
        return pivotIdx