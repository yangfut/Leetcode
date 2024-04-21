// DFS with cache
// Beats 8.51% in runtime and 21% in memory
class Solution {
public:
    bool hasValidPathHelper(vector<vector<int>>& grid, vector<vector<int>>& directions, int row, int col, int prevRow, int prevCol){
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || row == m || col < 0 || col == n || grid[row][col] == -1) return false;

        vector<int> next = directions[grid[row][col]];

        // Mark the current stree is visited
        grid[row][col] = -1;

        // Check one of the next move includes the prevRow and prevCol. Otherwise, it's invalud move
        if(prevRow >= 0 && prevCol >= 0){
            if(!((row+next[0] == prevRow && col+next[1] == prevCol) || (row+next[2] == prevRow && col+next[3] == prevCol))) return false;
        }
        if(row == m-1 && col == n-1) return true;

        // recurse for all possible direction we can go from current cell
        return hasValidPathHelper(grid, directions, row+next[0], col+next[1], row, col)
            || hasValidPathHelper(grid, directions, row+next[2], col+next[3], row, col);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{}, {0,-1,0,1}, {-1,0,1,0}, {0,-1,1,0}, {0,1,1,0}, {0,-1,-1,0}, {0,1,-1,0}};
        return hasValidPathHelper(grid, directions, 0, 0, -1, -1);
    }
};

// Optimized DFS with cache
// Beats 99% in runtime and 97% in memory
class Solution {
public:
    bool dfs(int row, int col, int flow, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || row == m || col < 0 || col == n || grid[row][col] == -1) return false;

        int curr = grid[row][col];
        grid[row][col] = -1;
        if(row == m-1 && col == n-1){
            if(flow == 2 && (curr == 1 || curr == 3 || curr == 5)) return true;
            if(flow == 4 && (curr == 2 || curr == 5 || curr == 6)) return true;
            return false;
        }

        // Check the previous direction(flow) and the incoming flow are possible
        if(curr == 1 && flow == 1) return dfs(row, col-1, 1, grid);
        if(curr == 1 && flow == 2) return dfs(row, col+1, 2, grid);
        if(curr == 2 && flow == 4) return dfs(row+1, col, 4, grid);
        if(curr == 2 && flow == 3) return dfs(row-1, col, 3, grid);
        if(curr == 3 && flow == 2) return dfs(row+1, col, 4, grid);
        if(curr == 3 && flow == 3) return dfs(row, col-1, 1, grid);
        if(curr == 4 && flow == 1) return dfs(row+1, col, 4, grid);
        if(curr == 4 && flow == 3) return dfs(row, col+1, 2, grid);
        if(curr == 5 && flow == 4) return dfs(row, col-1, 1, grid);
        if(curr == 5 && flow == 2) return dfs(row-1, col, 3, grid);
        if(curr == 6 && flow == 4) return dfs(row, col+1, 2, grid);
        if(curr == 6 && flow == 1) return dfs(row-1, col, 3, grid);
        
        // assume all other way lead to untraversable paths
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int curr = grid[0][0];
        if(grid.size() == 1 && grid[0].size() == 1) return true;
        if(curr == 5) return false;

        // flow signals:
        // 1. to the left   2: to the right
        // 3. to up         4. to down
        if(curr == 1) return dfs(0, 1, 2, grid);
        if(curr == 2) return dfs(1, 0, 4, grid);
        if(curr == 3) return dfs(1, 0, 4, grid);
        if(curr == 4) return dfs(0, 1, 2, grid) || dfs(1, 0, 4, grid);
        if(curr == 6) return dfs(0, 1, 2, grid);

        // should never be here
        return false;
    }
};