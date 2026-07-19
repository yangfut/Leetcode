class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int org = money;
        for(int i = 0; i < 2; ++i) money -= prices[i];
        return money < 0 ? org : money;
    }
};