#Reference on https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/1012572/Python3-dp-(prefix-sum)
class Solution:
    def maxSumTwoNoOverlap(self, A, L, M):
        prefix = [0]
        for x in A: prefix.append(prefix[-1] + x)
        ans = lmx = mmx = float('-inf')
        
        for i in range(M+L, len(A)+1):
            lmx = max(lmx, prefix[i-M] - prefix[i-M-L])
            mmx = max(mmx, prefix[i-L] - prefix[i-M-L])
            ans = max(ans, lmx + prefix[i] - prefix[i-M], mmx + prefix[i] - prefix[i-L])
        return ans

def main():
    sol = Solution()
    
    A = [0,6,5,2,2,5,1,9,4]
    L = 1
    M = 2
    #Output: 20
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
    A = [3,8,1,3,2,1,8,9,0]
    L = 3
    M = 2
    #Output: 29
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
    A = [2,1,5,6,0,9,5,0,3,8]
    L = 4
    M = 3
    #Output: 31
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
    A = [4,0,1]
    L = 2
    M = 1
    #Output: 5
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
    A = [4,5,14,16,16,20,7,13,8,15]
    L = 3
    M = 5
    #Output: 109
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
    A = [0,6,5,2,2,5,1,9,4]
    L = 1
    M = 2
    #Output: 20
    print(sol.maxSumTwoNoOverlap(A, L, M))
    
if __name__ == '__main__':
    main()
