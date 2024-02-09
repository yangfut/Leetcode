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