class Solution:
    def peakIndexInMountainArray(self, arr):
        st,ed = 0, len(arr)-1
        while st < ed:
            i = (st+ed) // 2
        
            if arr[i] < arr[i-1]:
                st,ed = st, i
            elif arr[i] < arr[i+1]:
                st,ed = i, ed
            elif arr[i] > arr[i+1] and arr[i] > arr[i-1]:
                return i

def main():
    sol = Solution()
    
    arr = [0,10,5,2]
    #Output: 1
    print(sol.peakIndexInMountainArray(arr))
    
    arr = [3,4,5,1]
    #Output: 2
    print(sol.peakIndexInMountainArray(arr))
    
    arr = [40,48,61,75,100,99,98,39,30,10]
    #Output: 
    print(sol.peakIndexInMountainArray(arr))
    
if __name__ == '__main__':
    main()
