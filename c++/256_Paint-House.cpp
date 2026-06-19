class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3,0);
        for(int i = 0; i < costs.size(); ++i){
            vector<int>tmp(3,0);
            for(int j = 0; j < 3; ++j){
                tmp[j] = costs[i][j] + min(dp[(j+1)%3], dp[(j+2)%3]);
            }
            dp = tmp;
        }
        return min(dp[0],min(dp[1], dp[2]));
    }
};