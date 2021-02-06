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
Reference to https://leetcode.com/problems/prison-cells-after-n-days/discuss/861468/Python-pigeonhole-principle-with-comment
class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
		# seen record already seen config from day 1, mod is the cycle days, start_loop_idx is from which seen[] index it starts to repeat itself
        seen = []
        mod, start_loop_idx = -1, -1
		# find the cycle
        for i in range(1, N+1):
            new_cell = [False] * 8
            for i in range(1, 7):
                new_cell[i] = not (cells[i-1] ^ cells[i+1])
            if new_cell in seen:
                start_loop_idx = seen.index(new_cell)
                mod = len(seen) - start_loop_idx
                break
            else:
                seen.append(new_cell)
            cells = new_cell
        
		# After knowing the cycle, we lookup list seen[] to find the answer we want
        r = N % mod
        index = start_loop_idx + r-1 if r-1>=0 else len(seen) -1
        res = seen[index]
        for i, v in enumerate(res):
            if v == True:
                res[i] = 1
            else:
                res[i] = 0
        return res
'''
