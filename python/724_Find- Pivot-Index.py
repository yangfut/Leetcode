'''
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
'''
class Solution:
    def pivotIndex(self, nums):
        '''
        #1
        #Time Complexity: O(n)
        #Space Complexity: O(n)
        leftSum = [nums[0]]*len(nums)
        rightSum = [nums[-1]]*len(nums)

        for i in range(1,len(nums)):
            leftSum[i] = leftSum[i-1] + nums[i]
            rightSum[-i-1] = rightSum[-i] + nums[-i-1]
            
        index = 0
        while index < len(nums):
            if(rightSum[index] == leftSum[index]):
                return index
            index += 1
        return -1
        '''
        #2
        #Time Complexity: O(n)
        #Space Complexity: O(1) 
        leftSum, rightSum = 0, sum(nums)

        for idx, ele in enumerate(nums):
            leftSum += ele
            if (leftSum == rightSum):
                return idx
            rightSum -= ele
        return -1






if __name__ == "__main__":
    sol = Solution()
    nums = [1,7,3,6,5,6]
    print(sol.pivotIndex(nums))

    nums = [1,2,3]
    print(sol.pivotIndex(nums))
    nums = [2,1,-1]
    print(sol.pivotIndex(nums))