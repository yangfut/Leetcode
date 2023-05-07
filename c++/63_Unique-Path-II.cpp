class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int wd = obstacleGrid[0].size();
    int ht = obstacleGrid.size();
    vector<vector<int>>dp(ht+1, vector<int>(wd+1, 0));

    dp[0][1] = 1;
    for(int m = 1; m <= ht; ++m){
        for(int n = 1; n <= wd; ++n){
            dp[m][n] = (dp[m-1][n] + dp[m][n-1]) * !obstacleGrid[m-1][n-1];
        }
    }
		return dp[ht][wd];
    }
};
