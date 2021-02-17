class Solution:
    def uniqueOccurrences(self, arr):
        dict ={}
        for key in arr:
            dict[key] = 1 + dict.get(key,0)
        
        table = [0] * 1001
        for val in dict.values():
            if table[val] == 1:
                return False
            table[val] += 1
        return True

def main():
    sol = Solution()
    
    arr = [1,2,2,1,1,3]
    #Output: true
    print(sol.uniqueOccurrences(arr))
    
    arr = [1,2]
    #Output: false
    print(sol.uniqueOccurrences(arr))
    
    arr = [-3,0,1,-3,1,1,1,-3,10,0]
    #Output: true
    print(sol.uniqueOccurrences(arr))
    
if __name__ == '__main__':
    main()
