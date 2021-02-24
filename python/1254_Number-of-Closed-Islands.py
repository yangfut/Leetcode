class Solution:
    
    def dfs_search(self, grid, y, x):
        if grid[y][x] == 0:
            if y == 0 or y == len(grid)-1 or x == 0 or x == len(grid[0])-1:
                return False
            grid[y][x] = -1
            ans = True
            for dy, dx in ((1,0),(0,1), (-1,0),(0,-1)):
                ans &= self.dfs_search(grid, y+dy, x+dx)
            return ans
        else:
            return True
            
                        
    def closedIsland(self, grid):
        if len(grid)<3 or len(grid[0])<3:
            return 0
        
        ans = 0
        for row in range(1, len(grid)-1):
            for col in range(1, len(grid[0])-1):
                if grid[row][col] == 0:
                    ans += self.dfs_search(grid, row, col)
        return ans
    
def main():
    sol = Solution()
    
    grid = [[1,1,1,1,1,1,1,0],
            [1,0,0,0,0,1,1,0],
            [1,0,1,0,1,1,1,0],
            [1,0,0,0,0,1,0,1],
            [1,1,1,1,1,1,1,0]]
    #Output: 2
    print(sol.closedIsland(grid))
    
    grid = [[0,1,1,1,0],[1,0,1,0,1],[1,0,1,0,1],[1,0,0,0,1],[0,1,1,1,0]]
    #Output: 1
    print(sol.closedIsland(grid))

if __name__ == '__main__':
    main()
