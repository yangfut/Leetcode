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
