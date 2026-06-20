class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(n, 0);
        if(n == 1) return k;
        if(n == 2) return k*k;
        dp[0] = k, dp[1] = k*k;
        
        // #1: color[i] != color[i-1]
        // dp[i] = dp[i-1] * (k-1)

        // #2: color[i] != color[i-2]
        // do[i] = dp[i-2] * (k-1)
        for(int i = 2; i < n; ++i){
            dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
        }
        return dp.back();
    }
};