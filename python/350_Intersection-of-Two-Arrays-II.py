class Solution:
    def intersect(self, nums1, nums2):
        dict = {}
        res = []
        
        for i in nums1:
            if i in dict:
                dict[i]+=1
            else:
                dict[i]=1
        
        for j in nums2:
            if j in dict and dict[j] !=0 :
                dict[j]-=1
                res.append(j)
        return res
    
def main():
    solution = Solution()
    
    nums1 = [1,2,2,1]; nums2 = [2,2]
    print(solution.intersect(nums1, nums2))
    #Output: [2,2]
    
    nums1 = [4,9,5]; nums2 = [9,4,9,8,4]
    print(solution.intersect(nums1, nums2))
    #Output: [4,9]
          
        

if __name__ == '__main__':
    main()
