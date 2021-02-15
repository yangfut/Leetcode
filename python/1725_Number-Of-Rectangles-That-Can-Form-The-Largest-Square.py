class Solution:
    def countGoodRectangles(self, rectangles):
        dict = {}
        for i, vals in enumerate(rectangles):
            tmp = vals[0] if vals[0] <= vals[1] else vals[1]
            dict[tmp] = 1 + dict.get(tmp,0)
        maxLen, maxKey = 1, 0
        
        for keys in dict.items():
            if keys[0]>maxKey:
                maxKey = keys[0]
                maxLen = keys[1]
        return maxLen
    
    
def main():
    s = Solution()

    rectangles = [[5,8],[3,9],[5,12],[16,5]]
    #Output: 3 
    print(s.countGoodRectangles(rectangles))

    
    rectangles = [[2,3],[3,7],[4,3],[3,7]]
    #Output: 3
    print(s.countGoodRectangles(rectangles))
    
if __name__ == '__main__':
    main()

