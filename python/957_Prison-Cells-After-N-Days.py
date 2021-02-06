class Solution:
    def prisonAfterNDays(self, cells, N):
        #Initialize
        m = [[0 for x in range(8)] for y in range(8)]
        m[0] = cells
    
        for day in range(1,8):
                for i in range(1,7):
                    if m[day-1][i-1] == m[day-1][i+1]:
                        m[day][i]=1
                    else:
                        m[day][i]=0
                        
        mod = N%14
        if mod <= 7 and mod >0:
            return m[mod]
        elif mod >7:
            return m[mod-7][::-1]
        elif mod ==0:
            return m[7][::-1]
    
def main():
    solution = Solution()
    
    cells = [0,1,0,1,1,0,0,1]
    N = 7
    print(solution.prisonAfterNDays(cells,N))
    
    cells = [1,0,0,1,0,0,1,0]
    N = 1000000000
    print(solution.prisonAfterNDays(cells,N))
    
    cells = [1,0,0,1,0,0,0,1]
    N = 826
    print(solution.prisonAfterNDays(cells,N))
    
    return None

if __name__ == '__main__':
    main()


