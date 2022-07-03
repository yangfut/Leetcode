class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if nums == None or len(nums)<3: return None
        nums.sort()
        ans = set()
        for i in range(len(nums)):
            j = i+1
            k = len(nums)-1
            while (j<k):
                sum = nums[i]+nums[j]+nums[k]
                if sum == 0:
                    ans.add((nums[i], nums[j], nums[k]))
                    j+=1
                    k-=1
                elif sum < 0:
                    j+=1
                elif sum > 0:
                    k-=1     
        return ans
