class Solution:
    def findMinArrowShots(self, points) -> int:
        if not points:
            return 0
        
        points.sort(key = lambda x:x[1])
        arrowCount, currBound = 1, points[0][1]
        
        for x_st, x_ed in points[1:]:
            if x_st > currBound:
                arrowCount += 1
                currBound = x_ed
            
        return arrowCount
    
    
def main():
    s = Solution()

    points = [[10,16],[2,8],[1,6],[7,12]]
    #Output: 2
    print(s.findMinArrowShots(points))

    
    points = [[1,2],[3,4],[5,6],[7,8]]
    #Output: 4
    print(s.findMinArrowShots(points))
    
    points = [[1,2]]
    #Output: 1
    print(s.findMinArrowShots(points))
    
    points = [[2,3],[2,3]]
    #Output: 1
    print(s.findMinArrowShots(points))
if __name__ == '__main__':
    main()

