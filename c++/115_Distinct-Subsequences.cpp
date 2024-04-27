class Solution {
public:
    int MOD = 1e9+7;
    int backtrack(string& s, int s_idx, string& t, int t_idx, vector<vector<int>>&  dp){
        
        // base case
        if(t_idx == t.length()) return 1;
        if(s_idx == s.length()) return 0;

        // caching
        if(dp[s_idx][t_idx] != -1) return dp[s_idx][t_idx];

        // Not pick
        dp[s_idx][t_idx] = backtrack(s, s_idx+1, t, t_idx, dp);

        // Pick
        if(s[s_idx] == t[t_idx]){
            dp[s_idx][t_idx] += backtrack(s, s_idx+1, t, t_idx+1, dp);
        }
        return dp[s_idx][t_idx];
    }

    int memo_solution(string& s, string& t){
        // Edge cases:
        if(t.length() > s.length()) return 0;

        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return backtrack(s, 0, t, 0, dp);
    }
    
    int tab_solution(string& s, string& t){
        int n = s.length(), m = t.length();
        // Edge cases:
        if(m > n) return 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // initialize padding
        for(int sIdx = 0; sIdx <= n; ++sIdx) dp[sIdx][m] = 1;

        for(int sIdx = n-1; sIdx >= 0; --sIdx){
            for(int tIdx = m-1; tIdx >= 0; --tIdx){

                // Exclude the current char
                // tempPath might be greater than INT_MAX
                long long tempPath = dp[sIdx+1][tIdx];

                // Include the current char
                if(s[sIdx] == t[tIdx]){
                    tempPath += dp[sIdx+1][tIdx+1];
                }   

                // If question is guaranteed there's no answer that is greater than INT_MAX, then we can assume 0 here
                if(tempPath > INT_MAX) tempPath = 0;
                dp[sIdx][tIdx] = tempPath;
            }
        }
        return dp[0][0];
    }


    // Question constraints:
    // 1 <= s.length(), t.length() <= 1000
    // s and t consist of English letters

    // Overflow consideration
    // if s.length == 1000 and all elements are 'a'
    // if t.legnth == 100 and all elements are 'a'
    // The possible subsequence are Permuation P(1000, 100). 
    // It's 1000!/100! = 1000*999*998*...*901 and can be approximatly simpified as 10^3 * 10^3 * ... * 10^3 = 10^300, which definitly leads overflow!

    int numDistinct(string s, string t) {
        // backtracking with memoization
        // return memo_solution(s, t);

        // tabulation
        // Quesion1: ask what's the maximum possible ways for distinct subsequence?
        // Quesion2: ask can I assume the maximum value to prevert overflow, like 1e9+7
        // dp[sIdx][tIdx] = dp[sIdx-1][tIdx] + dp[sIdx+1][tIdx+1] might cause overflow issue

        return tab_solution(s, t);
    }
};