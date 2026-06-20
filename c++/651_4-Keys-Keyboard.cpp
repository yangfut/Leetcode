// Tabulation
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i < n+1; ++i){
            dp[i] = dp[i-1] + 1;
            // find out the maximum values by pressing VVV...
            for(int j = 3; j <= i; ++j){
                dp[i] = max(dp[i], dp[i-j] * (j-1));
            }
        }
        return dp.back();
    }
};

// Memoization
class Solution {
public:
    int _maxA(int v, vector<int>& memo){
        if(v <= 0) return 0;
        if(memo[v] != -1) return memo[v];

        // Press 'A'
        memo[v] = _maxA(v-1, memo) + 1;

        // Press 'VVVV'
        for(int j = 3; j <= v; ++j){
            memo[v] = max(memo[v], _maxA(v-j, memo) * (j-1));
        }
        return memo[v];
    }
    int maxA(int n) {
        vector<int> memo(n+1, -1);
        memo[0] = 0;
        return _maxA(n, memo);
    }
};