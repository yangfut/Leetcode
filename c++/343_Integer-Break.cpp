class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59,0);
        dp[2] = 1, dp[3] = 2, dp[4] = 4, dp[5] = 6, dp[6] = 9;
        for(int i = 7; i <= n; ++i){
            dp[i] = max(dp[i-2] * 2, dp[i-3] * 3);
        }
        return dp[n];
    }
};