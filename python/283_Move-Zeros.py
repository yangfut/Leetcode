class Solution:
    def moveZeroes(self, nums):
        ii, jj, n = 0, 0, len(nums)
        while ii+1 < n and jj+1 < n:
            while nums[ii] == 0 and ii+1 < n:
                ii+=1
            while nums[jj] !=0 and jj+1 < n:
                jj+=1
            #nums[ii] is non-zero integer
            #nums[jj] is zero

            if ii > jj:
                nums[ii], nums[jj] = nums[jj], nums[ii]
            else:
                ii+=1
                
        return None


def main():
    sol = Solution()
    
    nums = [0,1,0,3,12]
    #Output: [1,3,12,0,0]
    sol.moveZeroes(nums)
    print(nums)
    
    
    nums = [1,0]
    #Output: [1,0]
    sol.moveZeroes(nums)
    print(nums)
    
    nums = [1,0, 1]
    #Output: [1,1,0]
    sol.moveZeroes(nums)
    print(nums)

    
if __name__ == '__main__':
    main()


