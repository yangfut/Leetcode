#include <iostream>     // std::cout
#include <algorithm>    // std::max

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>dp(amount+1, amount+1);

        dp[0] = 0;
        for(int ele : coins){
            for(int a = ele; a <= amount; ++a){
                dp[a] = min(dp[a - ele] + 1, dp[a]);
            }
        }
		return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


// Time Limit Exceeded
// coins = {186,419,83,408}
// amount = 6249
class Solution {
public:
    int memoization(vector<int>& memo, vector<int>& coins, int amount){
        // Edge case: the remain amount is less than the minimum coin
        if(amount < coins.front()) return -1;

        if(memo[amount]==-1){
            int minv = INT_MAX;
            for(int idx=coins.size()-1; idx>=0; --idx){
                int temp = memoization(memo, coins, amount-coins[idx]);
                if(temp!=-1) minv = min(minv, temp+1); 
                
            }
            // Indicate that this remain amount can't be made if minv is INT_MAX
            if(minv!=INT_MAX) memo[amount]=minv;
        }
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // Edge case: Don't pick any coin
        if(amount==0) return 0;
        sort(coins.begin(), coins.end());

        // Edge case: amount is less than the minimum coin(Impossible to make that amount!)
        if(amount < coins.front()) return -1;

        vector<int>memo(amount+1, -1);
        for(int& coinVal:coins) {
            if(coinVal>amount) break;
            memo[coinVal]=1;
        }
        return memoization(memo, coins, amount);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. 1D DP to store the minimum amounts of combinations

        // Edge case: Don't pick any coin
        if(amount==0) return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int& coinVal:coins){
            // Pick every coin and look forward dp[v] = min(dp[v], dp[v-coinVal] + 1)
            for(int v = coinVal; v <= amount; ++v){
                dp[v] = min(dp[v], dp[v-coinVal]+1);
            }
        }
        return (dp[amount]==amount+1)?-1:dp[amount];
    }
};