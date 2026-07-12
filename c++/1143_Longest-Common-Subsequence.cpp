class Solution {
public:    
    int tabulation_sol(string text1, string text2) {
        // Tabulation(bottom-up)
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = len1 - 1; i >= 0; --i){
            for(int j = len2 - 1; j >= 0; --j){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }

    int memo_sol(string text1, string text2){
        // Memoization(top-down)
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        // compare text1[i] and text2[j]
        for(int i=1; i<=len1; ++i){
            for(int j=1; j<=len2; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return tabulation_sol(text1, text2);

        return memo_sol(text1, text2);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int t = dp[i][j+1];
                int l = dp[i+1][j];
                int tl = dp[i][j];
                if(text1[i] == text2[j]) ++tl;
                dp[i+1][j+1] = max(t, max(l, tl));
            }
        }
        return dp[n][m];
    }
};