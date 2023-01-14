class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        
        '''
        #Solution_1
        l = len(nums)
        ans = [nums[0]]
        if l == (1 or 0):
            return nums
        for index in range(1, l):
            ans.append(ans[index-1]+nums[index])
        return ans
        '''
        #Solution_2
        for index in range(1, len(nums)):
            nums[index] = nums[index-1] + nums[index]
        return nums