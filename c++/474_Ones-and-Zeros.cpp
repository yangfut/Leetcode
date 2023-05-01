#include <iostream>  // std::count
#include <vector>       
#include <algorithm> // std::max
class Solution {
    public:
     	int findMaxForm(vector<string>& strs, int m, int n) {
            
            /*
            Explaination: 
            Since there are two constraints m and n, this is an 2-dimensional DP problem.
            The DP matrix stores the max numbers of subset string. Use the DP from bottm right in order to
            prevent the single string is selected twice.
            
            To consider whether the current string is selected, compare the current DP matrix(i, j) and the 
            matrix exactly losing current zeros and ones, like matrix(i-zeros, j-ones).
            
            */
            vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
            int zeros;
            int ones;
            for(int ele = 0; ele < strs.size(); ++ele){
                zeros = count(strs[ele].begin(), strs[ele].end(), '0');
                ones = strs[ele].size() - zeros;
                for(int i = m; i >= zeros; --i){
                    for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
                }
            }
            return dp[m][n];
        }
};
