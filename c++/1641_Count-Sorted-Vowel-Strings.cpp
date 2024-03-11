class Solution {
public:
    //Tabulation#1

    // int CVS(int n, int x, vector<vector<int>>&dp){
    //     if(dp[n][x]==-1) dp[n][x] = CVS(n, x+1, dp) + CVS(n-1, x, dp);
    //     return dp[n][x];
    // }
    // int countVowelStrings(int n) {
    //     vector<vector<int>>dp(n+1, vector<int>(5,-1));
    //     for(int i=0;i<5;i++) dp[1][i]=5-i;
    //     for(int i=1;i<=n;i++) dp[i][4]=1;
    //     return CVS(n, 0, dp);
    // }

    //Tabulation#2
    //"o" in 3 includes "o" in 2 plus "u" in 3
    int countVowelStrings(int n) {
        vector<int>dp(5,1);
        while(n){
            for(int i=3;i>=0;--i) dp[i]+=dp[i+1];
            --n;
        }

        return dp[0];
    }
};