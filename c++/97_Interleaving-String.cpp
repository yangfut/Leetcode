class Solution {
public:
    bool memo_solution(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        
        // base case
        if(k<0) return (i<0 && j<0);
        
        // caching
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];

        bool l = false, r = false;
        if(i>=0 && s1[i]==s3[k]){
            // Pick left
            l = memo_solution(i-1, j, k-1, s1, s2, s3, dp);
        }

        if(j>=0 && s2[j]==s3[k]){
            // Pick right
            r = memo_solution(i, j-1, k-1, s1, s2, s3, dp);
        }

        if(i>=0 && j>=0) dp[i][j] = l || r;
        return l||r;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len3 == 0) return len1 == 0 && len2 == 0;
        if(len1 == 0) return s2 == s3;
        if(len2 == 0) return s1 == s3;
        vector<vector<int>> dp(len1, vector<int>(len2, -1));

        // backtracking from TAIL with memoization
        return memo_solution(len1-1, len2-1, len3-1, s1, s2, s3, dp);
    }
};

class Solution {
public:
    bool MemoHelper(string& s1, int idx1, string& s2, int idx2, string& s3, vector<vector<int>>& dp){
        int idx3 = idx1 + idx2;

        // base case
        if(idx3 == s3.length()){
            return idx1 == s1.length() && idx2 == s2.length();
        }

        // caching
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        bool l = false, r = false;
        if(idx1 < s1.length() && s1[idx1] == s3[idx3]){
            // Pick from s1
            l = MemoHelper(s1,idx1+1, s2, idx2, s3, dp);
        }

        if(idx2 < s2.length() && s2[idx2] == s3[idx3]){
            // Pick from s2
            r = MemoHelper(s1, idx1, s2, idx2+1, s3, dp);
        }

        return dp[idx1][idx2] = l || r;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.empty()) return s1.empty() && s2.empty();

        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return MemoHelper(s1, 0, s2, 0, s3, dp);
    }
};