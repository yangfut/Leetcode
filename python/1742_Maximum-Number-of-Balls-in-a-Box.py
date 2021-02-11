class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        n = highLimit - lowLimit + 1
        Table = [0] * 46
        
        for i in range(lowLimit, highLimit+1):
            out = 0
            while i > 0:
                res = i % 10
                out += res
                i = i // 10
            
            Table[out] += 1
        return max(Table)
    
    
def main():
    s = Solution()
    
    lowLimit = 1
    highLimit = 10
    #Output: 2
    print(s.countBalls(lowLimit, highLimit))

    
    lowLimit = 5
    highLimit = 15
    #Output: 2
    print(s.countBalls(lowLimit, highLimit))

    
    lowLimit = 19
    highLimit = 28
    #Output: 2
    print(s.countBalls(lowLimit, highLimit))
    
    lowLimit = 11
    highLimit = 104
    #Output: 9
    print(s.countBalls(lowLimit, highLimit))
    
    lowLimit = 6745
    highLimit = 28696
    print(s.countBalls(lowLimit, highLimit))

    
if __name__ == '__main__':
    main()

