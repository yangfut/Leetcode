class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int maxSize = triangle.back().size();
        vector<int> minSum(maxSize, 0);
        for(auto& row : triangle){
            for(int i = row.size()-1; i >= 0; --i){
                int prevR = (row.size() - 1) == i ? INT_MAX : minSum[i];
                int prevL = i-1 < 0 ? INT_MAX : minSum[i-1];
                if(min(prevR, prevL) == INT_MAX) minSum[i] = row[i];
                else minSum[i] = (min(prevR, prevL) + row[i]);
            }
        }

        int minT = INT_MAX;
        for(int val : minSum) minT = min(minT, val);
        return minT;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        // tabulation
        for(int row = triangle.size() - 2; row >= 0; --row){
            int n = triangle[row].size();
            for(int i = 0; i < n; ++i){
                dp[i] = min(dp[i], dp[i+1]) + triangle[row][i];
            }
        }
        return dp[0];
    }
};