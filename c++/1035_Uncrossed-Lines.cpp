class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                // Hit
                int tl = dp[i-1][j-1];
                int t = dp[i-1][j];
                int l = dp[i][j-1];
                if(nums1[i-1] == nums2[j-1]) ++tl;
                dp[i][j] = max(max(t,l),tl);
            }
        }
        return dp[n][m];
    }
};