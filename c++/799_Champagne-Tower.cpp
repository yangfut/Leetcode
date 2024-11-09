class Solution {
    double getVolume(int row, int col, vector<vector<double>> &memo){
        
        // boundary
        if(col < 0 || row < col) return 0;

        // memoization
        if(memo[row][col] != -1) return memo[row][col];

        //recursion
        double left = getVolume(row-1, col-1, memo);
        double right = getVolume(row-1, col, memo);
        left = (left > 1) ? (left-1)/2 : 0;
        right = (right > 1) ? (right-1)/2 : 0;

        return memo[row][col] = left + right;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;

        // V(i,j) = (V(i-1,j-1)-1)/ 2 + (V(i-1,j)-1)/2
        // Mark all cells -1 as unvisited
        vector<vector<double>> memo(query_row+1, vector<double>(query_row+1, -1));
        memo[0][0] = poured;
        double v = getVolume(query_row, query_glass, memo);
        return v > 1 ? 1 : v;
    }
};