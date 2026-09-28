class Solution {
public:
    int numberOfWays(int numPeople) {
        int n = numPeople;
        int MOD = 1000000007;
        vector<long long> dp(numPeople+1,0);
        dp[0] = 1;
        dp[2] = 1;
        for(int i = 4; i <= n; i += 2){
            for(int l = 0; l <= i - 2; l+=2){
                int r = i - 2 - l;
                dp[i] = (dp[i] + (dp[l] * dp[r])) % MOD;
            }
        }
        return dp.back();
    }
};