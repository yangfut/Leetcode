class Solution {
public:
    int dfsIslandArea(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()) return 0;
        if(1 != grid[row][col]) return 0 ;

        grid[row][col] = 2; //visisted

        return 1 + dfsIslandArea(grid, row-1, col)
            + dfsIslandArea(grid, row+1, col)
            + dfsIslandArea(grid, row, col-1)
            + dfsIslandArea(grid, row, col+1);  
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(1 == grid[row][col]){
                    maxArea = max(maxArea, dfsIslandArea(grid, row, col));
                }
            }
        }
        
        return maxArea;
    }
};