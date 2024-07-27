class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

class Solution {
public:
    vector<int> memo = vector<int>(46, -1);
    int climbStairs(int n) {
        if (n <= 2) return n;
        if(memo[n] == -1){
            return memo[n] = climbStairs(n-2) + climbStairs(n-1);
        }
        return memo[n];
    }
};