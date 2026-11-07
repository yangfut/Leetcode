class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int cnt = 0;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(matrix[r][c] == 0) continue;
                if(r == 0 || c == 0) {
                    dp[r][c] = 1;
                } else {
                    dp[r][c] = min({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]}) + 1;
                }
                cnt += dp[r][c];
            }
        }
        return cnt;
    }
};