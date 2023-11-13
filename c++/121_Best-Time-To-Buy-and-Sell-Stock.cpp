#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int stock = prices[0];

        for(int idx = 1; idx < prices.size(); idx++){
            profit = max(profit, prices[idx]-stock);
            stock = min(stock, prices[idx]);
        }
        return profit;
    }
};