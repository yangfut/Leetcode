class Solution:
    def maxProduct(self, nums):
        if nums[0] >= nums[1]:
            max_v, sec_v = nums[0], nums[1]
        else:
            max_v, sec_v = nums[1], nums[0]
            
        for val in nums[2:]:
            
            if val >= max_v:
                sec_v = max_v
                max_v = val
            elif val > sec_v:
                sec_v = val
        return (max_v-1) * (sec_v-1)
    
    
def main():
    s = Solution()

    nums = [3,4,5,2]
    #Output: 12 
    print(s.maxProduct(nums))

    
    nums = [1,5,4,5]
    #Output: 16
    print(s.maxProduct(nums))
    
    nums = [3,7]
    #Output: 12
    print(s.maxProduct(nums))
    
if __name__ == '__main__':
    main()

