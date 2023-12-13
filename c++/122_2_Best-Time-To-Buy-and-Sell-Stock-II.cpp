class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ptr1 = 0;
        int ptr2 = 0;

        int overall = 0;
        int profit = 0;

        for(ptr1=0; ptr1<prices.size(); ptr1++){
            if(prices[ptr1]-prices[ptr2] > profit){
                profit = prices[ptr1]-prices[ptr2];
            }else{
                ptr2 = ptr1;
                overall += profit;
                profit = 0;
            }
        }

        return overall+profit;
    }
};