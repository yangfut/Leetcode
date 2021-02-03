class Solution:
    def intersect(self, nums1, nums2):
        hash1 = {}
        hash2 = {}
        res = []
        
        for i in nums1:
            if i in hash1:
                hash1[i]+=1
            else:
                hash1[i]=1
        
        for j in nums2:
            if j in hash2:
                hash2[j]+=1
            else:
                hash2[j]=1

        for key, val in hash1.items():
            if key in hash2:
                count = min(hash1[key],hash2[key])
                for c in range(count):
                    res.append(key)
                
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



