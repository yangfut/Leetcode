class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint32_t> dp(amount+1,0);
        dp[0] = 1;
        for(int coin : coins){
            for(int i = 1; i <= amount; ++i){
                if(i - coin < 0) continue;
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};

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

class Solution {
public:

    int backtracking(vector<vector<int>>& memo, vector<int>& coins, int remaining, int idx){
        
        // base case
        if(remaining == 0) return 1;
        if(idx >= coins.size() || remaining < 0) return 0; // return 0 if invalid result

        // caching
        if(memo[idx][remaining] != -1) return memo[idx][remaining];

        // Include the coin at the current index
        int count = backtracking(memo, coins, remaining - coins[idx], idx);

        // Exclude the coin at the current index
        count += backtracking(memo, coins, remaining, idx+1);

        memo[idx][remaining] = count;

        return memo[idx][remaining];
    }
    int memo_sol(int amount, vector<int>& coins) {
        int n = coins.size();
        // Memoization(top-down) -> breaking amount from 5 to 0
        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        return backtracking(memo, coins, amount, 0);
    }
    int tab_sol(int amount, vector<int>& coins){
        int n = coins.size();
        // 2D-DP solution
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int idx = 1; idx <= n; ++idx){
            int val = coins[idx-1];
            dp[idx][0] = 1;
            for(int a=1; a <= amount; ++a){
                dp[idx][a] = dp[idx-1][a] + ( a-val >=0 ? dp[idx][a-val] : 0);
            }
        }
        return dp.back().back();
    }

    int optimized_tab_sol(int amount, vector<int>& coins){
        // Edge cases
        if(coins.size()==1 || amount == 0) return amount % coins[0] == 0;

        // 1D-DP
        vector<int>dp(amount+1, 0);
        dp[0] = 1;

        for(int& coin : coins){
            for(int a=1; a<=amount; ++a){
                dp[a] = dp[a] + (a-coin >= 0 ? dp[a-coin] : 0);
            }
        }
        return dp.back();
    }
    int change(int amount, vector<int>& coins) {
        // backtracking with memoization
        // return memo_sol(amount, coins);

        // 2D DP with tabulation
        // return tab_sol(amount, coins);

        // 1D DP with tabulation
        return optimized_tab_sol(amount, coins);
    }
};