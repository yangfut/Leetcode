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

'''
Another method found in Leetcode referred to https://maxming0.github.io/2020/07/03/Prison-Cells-After-N-Days/

class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        dic = {}
        while N > 0:
            dic[''.join(map(str, cells))] = N
            N -= 1
            tmp = [0] * 8
            for i in range(1, 7):
                tmp[i] = 1 if cells[i - 1] == cells[i + 1] else 0
            cells = tmp
            t = ''.join(map(str, cells))
            if t in dic:
                N = N % (dic[t] - N)
        return cells
