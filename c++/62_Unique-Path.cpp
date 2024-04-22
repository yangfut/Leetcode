#include <iostream>
#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 1));
        for(int down = 1; down < m; ++down){
            for(int right = 1; right < n; ++right){
                dp[down][right] = dp[down-1][right] + dp[down][right-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Edge cases:
        if(m == 1 || n == 1) return 1;

        vector<vector<int>> memo(m, vector<int>(n, 1));

        // memo[m][n] = memo[m-1][n] + memo[m][n-1];
        for(int row = 1; row < m; ++row){
            for(int col = 1; col < n; ++col){
                memo[row][col] = memo[row-1][col] + memo[row][col-1];
            }
        }
        return memo.back().back();
    }
};