class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #Time:89%, Space:98%
        if len(nums)==1 or k==0:
            return

        clone = [ele for ele in nums]
        
        idx = 0
        if k > len(nums):
            k = k%len(nums)

        for ed in range(k*-1, 0):
            nums[idx] = clone[ed]
            idx+=1
        for st in range(0,len(nums)-k):
            nums[idx] = clone[st]
            idx+=1