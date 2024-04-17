class Solution {
public:
    // Solution#1 - Depth-First Search
    // TC: O(N*M+V), SC: O(1)
    void dfs(vector<vector<char>>& grid, int x, int y){
        // bundary checking
        if(x<0 || y<0 || x>grid.size()-1 || y>grid[0].size()-1) return;

        // return if current position is already visited or of water
        if(grid[x][y] == '2' || grid[x][y] == '0') return;

        grid[x][y] = '2';

        // Do DFS in all 4 directions
        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }

    // Solution
};

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()) return;
        if(grid[row][col] != '1') return;

        grid[row][col] = '-'; //visisted
        
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(grid[row][col] == '1'){
                    ++count;
                    dfs(grid, row, col);
                }
            }
        }
        return count;
    }
};