class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<2) return min(cost.back(), cost.front());
        int n=cost.size();
        int dp[n+1];

        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;++i) dp[i]=min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        return dp[n];
    }
};

// Tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo = vector<int>(cost.size()+1, -1);
        memo[0] = 0;
        memo[1] = 0;
        for(int i = 2; i <= cost.size(); ++i){
            memo[i] = min(memo[i-1]+cost[i-1], memo[i-2]+cost[i-2]);
        }
        return memo.back();
    }
};