class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(int ele : coins){
            for(int a = ele; a <= amount; ++a){
                dp[a] = dp[a] + dp[a-ele];
            }
        }
        return dp[amount];
    }
};
