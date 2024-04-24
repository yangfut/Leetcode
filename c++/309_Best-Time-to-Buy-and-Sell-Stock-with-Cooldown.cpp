class Solution {
public:
    int dpHelper(vector<int>& prices, vector<vector<int>>& dp, int idx, int buying){
        
        //base case
        if(idx >= dp.size()) return 0;

        //caching
        if(dp[idx][buying] != -1) return dp[idx][buying];

        int cooldown = dpHelper(prices, dp, idx+1, buying);
        if(buying){
            int buyCurrent = dpHelper(prices, dp, idx+1, !buying) - prices[idx];
            dp[idx][buying] = max(buyCurrent, cooldown);
        }else{
            int sellCurrent = dpHelper(prices, dp, idx+2, !buying) + prices[idx];
            dp[idx][buying] = max(sellCurrent, cooldown);
        }
        return dp[idx][buying];

    }
    int maxProfit(vector<int>& prices) {
        // 2D-DP solution
        // int n = prices.size();
        // vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        // // s: sell at prices[s], b: buy at prices[b]
        // for(int s=2; s<n+2; ++s){
        //     // only valid if b <= s
        //     for(int b=2; b<=s; ++b){
        //         dp[s][b] = max(dp[s][b-1], dp[s-1][b]);
        //         if(prices[s-2] > prices[b-2]){
        //             dp[s][b] = max(dp[s][b], prices[s-2] - prices[b-2] + dp[b-2][b-2]);
        //         }
        //     }
        // }

        // return dp.back().back();

        // 1D-DP solution
        // int n = prices.size();
        // if(n==1) return 0;
        // vector<int> dp(n+2, 0);

        // for(int s = 3; s<n+2; ++s){
        //     int temp = dp[s-1];
        //     for(int b = 2; b<s; ++b){
        //         temp = max(temp, prices[s-2] - prices[b-2] + dp[b-2]);
        //     }
        //     dp[s] = temp;
        // }
        // return dp.back();

        // Decision tree with caching
        int n = prices.size();
        // Edge case
        if(n == 1) return 0;

        // State of buying or sell?
        // dp[i][1] -> buying at index i
        // dp[i][0] -> selling at index i
        vector<vector<int>>dp(n, {-1, -1});
        return dpHelper(prices, dp, 0, 1);

    }
};