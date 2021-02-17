class Solution:
    def relativeSortArray(self, arr1, arr2):
        dict={}
        nums,ans = [], []
        
        for val in arr2:
            dict[val] = 0
        
        for val in arr1:
            if val not in dict:
                nums.append(val)
            else: 
                dict[val] += 1
                
        for key, val in dict.items():
            ans.extend([key for _ in range(val)])
        
        ans.extend(sorted(nums))
        return ans

def main():
    sol = Solution()
    
    arr1 = [2,3,1,3,2,4,6,7,9,2,19]
    arr2 = [2,1,4,3,9,6]
    #Output: [2,2,2,1,4,3,3,9,6,7,19]
    print(sol.relativeSortArray(arr1, arr2))
    
if __name__ == '__main__':
    main()
