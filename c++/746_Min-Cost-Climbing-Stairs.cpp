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