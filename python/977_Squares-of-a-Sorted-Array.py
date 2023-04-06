class Solution:
    #Time:57%, Space:41%
    def sortedSquares(self, nums: List[int]) -> List[int]:
        if nums[0]>=0:
            return [ele**2 for ele in nums]
        if nums[-1]<=0:
            return [ele**2 for ele in nums[::-1]]
    
        st, ed = 0, len(nums)-1
        ans = [None]*len(nums)
        tail = -1     

        while (ed>=st):
            if abs(nums[st]) >= abs(nums[ed]):
                ans[tail] = nums[st]**2
                st+=1
            else:
                ans[tail] = nums[ed]**2
                ed-=1
            tail-=1
        return ans