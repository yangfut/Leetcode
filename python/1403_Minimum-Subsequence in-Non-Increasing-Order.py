class Solution:
    def minSubsequence(self, nums):
        hashTable = [0] * 101
        sumVal, hashIndex = 0, 100
        ans = []
        for val in nums:
            sumVal += val
            hashTable[val] += 1
            
        currVal = sumVal // 2
        
        while(hashIndex > 0):
            if hashTable[hashIndex] == 0:
                hashIndex -= 1
                continue
            if currVal >= 0:
                ans.append(hashIndex)
                currVal -= hashIndex
                hashTable[hashIndex] -= 1
            if currVal < 0:
                return ans
def main():
    s = Solution()
    
    nums = [4,3,10,9,8]
    #Output: [10,9]
    print(s.minSubsequence(nums))
    
    nums = [4,4,7,6,7]
    #Output: [7,7,6] 
    print(s.minSubsequence(nums))
    
    nums = [6]
    #Output: [6]
    print(s.minSubsequence(nums))
    
if __name__ == '__main__':
    main()
