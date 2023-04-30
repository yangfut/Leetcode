class Solution {
public:
    /*
    Reference:
    https://leetcode.com/problems/maximal-square/solutions/1632145/c-java-python-easy-to-solve-detailed-explanation-of-dp-with-visualization-and-dry-run/
    */
    int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();     //vertical length
    int n = matrix[0].size();  //horizontal length
    int maxSqr = 0;
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i < m + 1; ++i){
        for (int j = 1; j < n + 1; ++j){
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxSqr = max(maxSqr, dp[i][j]);
            }
        }
    }
    return maxSqr * maxSqr;
    }
};
