class Solution:
    def busyStudent(self, startTime, endTime, queryTime):
        count = 0
        for i,j in zip(startTime, endTime):
            if i <= queryTime and j >= queryTime:
                count += 1 
        return count
    
def main():
    solution = Solution()
    
    startTime = [1,2,3]
    endTime = [3,2,7]
    queryTime = 4
    print(solution.busyStudent(startTime, endTime, queryTime))
    #Output: 1

    startTime = [4]
    endTime = [4]
    queryTime = 4
    print(solution.busyStudent(startTime, endTime, queryTime))
    #Output: 1
    
    startTime = [4]
    endTime = [4]
    queryTime = 5
    print(solution.busyStudent(startTime, endTime, queryTime))
    #Output: 0
    
    startTime = [1,1,1,1]
    endTime = [1,3,2,4]
    queryTime = 7
    print(solution.busyStudent(startTime, endTime, queryTime))
    #Output: 0
    
    startTime = [9,8,7,6,5,4,3,2,1]
    endTime = [10,10,10,10,10,10,10,10,10]
    queryTime = 5
    print(solution.busyStudent(startTime, endTime, queryTime))
    #Output: 5
    
    return None

if __name__ == '__main__':
    main()

