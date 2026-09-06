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

// Monotonic stack
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxSeq = 0;
        vector<int> acc(m,0);
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(matrix[r][c] == '1') acc[c] += 1;
                else acc[c] = 0;
            }

            stack<int>st;
            vector<int>nls(m,m);
            vector<int>pls(m,-1);
            // nls
            for(int c = m-1; c >= 0; --c){
                while(!st.empty() && acc[st.top()] >= acc[c]) st.pop();
                if(!st.empty()) nls[c] = st.top();
                st.push(c);
            }

            while(!st.empty()) st.pop();
            // pls
            for(int c = 0; c < m; ++c){
                while(!st.empty() && acc[st.top()] >= acc[c]) st.pop();
                if(!st.empty()) pls[c] = st.top();
                st.push(c);
            }

            for(int c = 0; c < m; ++c){
                maxSeq = max(maxSeq, min(nls[c] - pls[c] - 1, acc[c]));
            }
        }
        return maxSeq * maxSeq;
    }
};

// 2D-DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxSide = 0;
        // dp: store the max side of square
        // To expand the square by one, need to determine the square from left, top, diagonal
        for(int r = 1; r <= n; ++r){
            for(int c = 1; c <= m; ++c){
                if(matrix[r-1][c-1] == '1'){
                    int tempMin = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]);
                    dp[r][c] = tempMin + 1;
                }
                maxSide = max(dp[r][c], maxSide);   
            }
        }
        return maxSide * maxSide;
    }
};