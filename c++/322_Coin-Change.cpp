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
