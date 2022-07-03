class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = dict()
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = 1
            else:
                d[nums[i]] += 1
        return max(d, key = lambda x:d.get(x))
        
