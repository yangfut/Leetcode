class Solution:
    def canFormArray(self, arr, pieces) -> bool:
        hash_t = 101 * [0]
        for i in range(len(arr)):
            hash_t[arr[i]] += i+1
        
        for p in pieces:
            tmp = hash_t[p[0]]
            if(tmp<1):
                return False
            
            for ii in range(1,len(p)):
                if(hash_t[p[ii]] != tmp+ii):
                    return False
        return True
    
def main():
    solution = Solution()
    
    arr = [12]
    pieces = [[1]]
    print(solution.canFormArray(arr, pieces))
    #Output : false

    arr = [85]
    pieces = [[85]]
    print(solution.canFormArray(arr, pieces))
    #Output: true
    
    arr = [15,88]
    pieces = [[88],[15]]
    print(solution.canFormArray(arr, pieces))
    #Output: true
    
    arr = [49,18,16]
    pieces = [[16,18,49]]
    print(solution.canFormArray(arr, pieces))
    #Output: false
    
    arr = [91,4,64,78]
    pieces = [[78],[4,64],[91]]
    print(solution.canFormArray(arr, pieces))
    #Output: true
    
    arr = [1,3,5,7]
    pieces = [[2,4,6,8]]
    print(solution.canFormArray(arr, pieces))
    #Output: false

    return None

if __name__ == '__main__':
    main()


