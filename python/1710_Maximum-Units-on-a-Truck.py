class Solution:
    def maximumUnits(self, boxTypes, truckSize: int):
        hashmap = [0]*1001
        
        for n, unit in boxTypes: 
            hashmap[unit] += n
        
        ptr = 1000
        maxUnits=0
        for i in range(1000,0,-1):
            if hashmap[i] !=0:
                if hashmap[i] < truckSize:
                    truckSize-=hashmap[i]
                    maxUnits+=(i*hashmap[i])
                    continue
                if hashmap[i] >= truckSize:
                    maxUnits+=(i*truckSize)
                    break
        return maxUnits


def main():
    sol = Solution()
    boxTypes = [[1,3],[2,2],[3,1]]
    truckSize = 4
    print(sol.maximumUnits(boxTypes, truckSize))
    boxTypes = [[5,10],[2,5],[4,7],[3,9]]
    truckSize = 10
    print(sol.maximumUnits(boxTypes, truckSize))
    boxTypes = [[2,1],[4,4],[3,1],[4,1],[2,4],[3,4],[1,3],[4,3],[5,3],[5,3]]
    truckSize = 13
    print(sol.maximumUnits(boxTypes, truckSize))

if __name__ == '__main__':
    main()
