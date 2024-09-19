class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int temp_profit = 0;
        int s_idx = 0;
        
        for(int idx = 1; idx < prices.size(); idx++){
            if(prices[idx] < prices[s_idx]){
                profit += temp_profit;
                temp_profit = 0;
            }else{
                temp_profit += (prices[idx] - prices[s_idx]);
                
            }
            s_idx = idx;
        }

        if(temp_profit != 0) profit+=temp_profit;
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int hold = INT_MAX;
        int profit = 0;

        for(int p : prices){
            if(p > hold) profit += (p - hold);
            hold = p;
        }
        return profit;        
    }
};