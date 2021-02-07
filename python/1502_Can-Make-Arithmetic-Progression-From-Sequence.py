class Solution:
    def canMakeArithmeticProgression(self, arr):
        self.quicksort(arr,0,len(arr)-1)
        diff = arr[1] - arr[0]
        for index in range(2,len(arr)):
            if diff != arr[index] - arr[index-1]:
                return False

        return True
    
    def quicksort(self,arr,start,end):
        if start < end:     
            pivot, ii, jj = start, start, end
            while(ii+1 < jj):
                
                while(arr[ii] <= arr[pivot] and ii < jj):
                    ii+=1
                while(arr[jj] > arr[pivot] and ii < jj):
                    jj-=1
                arr[ii], arr[jj] = arr[jj], arr[ii]


            if arr[pivot] < arr[ii]: 
                ii-=1
            arr[pivot], arr[ii] = arr[ii], arr[pivot]
            self.quicksort(arr,start,ii-1)
            self.quicksort(arr,ii+1,end)
        
def main():
    solution = Solution()
    
    arr = [3,5,1]
    print(solution.canMakeArithmeticProgression(arr))
    
    arr = [1,2,4]
    print(solution.canMakeArithmeticProgression(arr))
    

    arr = [-1099,-1527,-3025,-2276,-1206,-885,-4630,-4951,-1313,-4202,-4416,-3560,-243,-2597,78]
    print(solution.canMakeArithmeticProgression(arr))
    
    return None

if __name__ == '__main__':
    main()

