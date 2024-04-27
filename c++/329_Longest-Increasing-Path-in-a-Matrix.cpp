class Solution {
public:
    bool isValid(vector<vector<int>>& matrix, int val, int x, int y){
        //Go back if out of bounds
        if(x<0 || x>matrix.size()-1 || y<0 || y>matrix[0].size()-1) return false;
        //Go back if number is not increasing
        if(val>=matrix[x][y]) return false;
        
        return true;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int x, int y){
        int curP=1;
        int offset_list[]={-1, 1};
        
        for(int offset:offset_list){
            if(isValid(matrix, matrix[x][y], x+offset, y)){
                if(0==cache[x+offset][y]) dfs(matrix, cache, x+offset, y);
                curP=max(curP, 1+cache[x+offset][y]);
            }
 
            if(isValid(matrix, matrix[x][y], x, y+offset)){
                if(0==cache[x][y+offset]) dfs(matrix, cache, x, y+offset);
                curP=max(curP, 1+cache[x][y+offset]);
            }
        }
        cache[x][y]=curP;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxP=1;
        for(int i=0; i<matrix.size();i++){
            for(int j=0; j<matrix[0].size();j++){
                if(0==cache[i][j]) dfs(matrix, cache, i, j);
                maxP=max(maxP, cache[i][j]);
            }
        }

        return maxP;
    }
};

class Solution {
public:
    int dfsHelper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col){
        // caching
        if(dp[row][col] != -1) return dp[row][col];

        int r_offset[] = {-1, 0, 1, 0};
        int c_offset[] = {0, -1, 0, 1};
        int tempPath = 1, m = matrix.size(), n = matrix[0].size();
        for(int k = 0; k < 4; ++k){
            int r = r_offset[k], c = c_offset[k];
            // Exclude invalid indices
            if(row+r < 0 || row+r == m || col+c < 0 || col+c == n || matrix[row][col] >= matrix[row+r][col+c]) continue;

            tempPath = max(tempPath, 1 + dfsHelper(matrix, dp, row+r, col+c));
        }
        return dp[row][col] = tempPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // 1. iterate all elements in m x n matrix
        // 2. Update maxPath if dp[row][col] > maxPath
        // 3. dp[row][col] = 1 + max(dp[row+r][col+c] within "four directions")
        int m = matrix.size(), n = matrix[0].size(), maxPath = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(dp[row][col] == -1) dp[row][col] = dfsHelper(matrix, dp, row, col);
                maxPath = max(maxPath, dp[row][col]);
            }
        }

        return maxPath;
    }
};