class Solution {
public:
    int memoHelper(string& word1, int idx1, string& word2, int idx2, vector<vector<int>>& dp){

        //base case
        if(idx2 == word2.length()) return word1.length() - idx1;
        if(idx1 == word1.length()) return word2.length() - idx2;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2]){
            dp[idx1][idx2] = 0 + memoHelper(word1, idx1+1, word2, idx2+1, dp);
        }else{
            int insert = 1 + memoHelper(word1, idx1, word2, idx2+1, dp);
            int del = 1 + memoHelper(word1, idx1+1, word2, idx2, dp);
            int replace = 1 + memoHelper(word1, idx1+1, word2, idx2+1, dp);
            dp[idx1][idx2] = min(insert, min(del, replace));
        }

        return dp[idx1][idx2];

    }

    int memo_solution(string& word1, string& word2){
        if(word1.empty()) return word2.length();
        if(word2.empty()) return word1.length();
        
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return memoHelper(word1, 0, word2, 0, dp);
    }

    int tab_solution(string& word1, string& word2){
        int len1 = word1.length(), len2 = word2.length();
        if(word1.empty()) return word2.length();
        if(word2.empty()) return word1.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        // padding values is reverse of idx representing the result of length needs to be handled
        // For dp[0][len2], the rest of word1 elements in length of len1 should be deleted
        // for dp[len1][0], the rest of word2 elements in length of len2 should be inserted

        // Think about ("e", "ros") first before figuring the initalizing lines
        for(int i = 0; i < len1; ++i) dp[i][len2] = len1-i;
        for(int i = 0; i < len2; ++i) dp[len1][i] = len2-i;

        for(int row = len1-1; row >= 0; --row){
            for(int col = len2-1; col >=0; --col){
                if(word1[row] == word2[col]){
                    dp[row][col] = dp[row+1][col+1];
                }else{
                    // min of (delete, insert, replace)
                    dp[row][col] = 1 + min(dp[row+1][col], min(dp[row][col+1], dp[row+1][col+1]));
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        // backtracking with memoization
        // return memo_solution(word1, word2);

        // tabulation
        return tab_solution(word1, word2);
    }
};