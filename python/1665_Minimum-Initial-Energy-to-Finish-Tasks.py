class Solution:
    def minimumEffort(self, tasks):
        tasks.sort(key = lambda x:x[1]-x[0], reverse = True)
        energy = tasks[0][1]
        remain = tasks[0][1] - tasks[0][0]
       
        for cost, threshold in tasks[1:]:
            if remain < threshold:
                energy += (threshold - remain)
                remain = threshold - cost
            else:
                remain -= cost
                
        return energy

def main():
    s = Solution()
    
    tasks = [[1,2],[2,4],[4,8]]
    #Output: 8
    print(s.minimumEffort(tasks))
    
    tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
    #Output: 32 
    print(s.minimumEffort(tasks))
    
    tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
    #Output: 27
    print(s.minimumEffort(tasks))
    
if __name__ == '__main__':
    main()
