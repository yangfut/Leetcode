class Solution {
public:
    vector<vector<bool>> createPalindromePartitionMatrix(string s){
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int len=1;len<=n;++len){
            for(int st=0;st<=n-len;++st){
                int ed=st+len-1;
                if(len==1) dp[st][ed]=true;
                else if(len==2) dp[st][ed]=(s[st]==s[ed]);
                else dp[st][ed] = (s[st]==s[ed]&&dp[st+1][ed-1]);
            }
        }
        return dp;
    }
    void backtrack(string s, vector<vector<bool>>& dp, int start, vector<string>& buffer, vector<vector<string>>& result){
        if(start==s.size()){
            result.push_back(buffer);
            return;
        }

        for(int end=start; end<s.size();++end){
            if(dp[start][end]){
                buffer.push_back(s.substr(start, end-start+1));
                backtrack(s, dp, end+1, buffer, result);
                buffer.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // 1. Precompute palindrome matrix
        // 2. If found palindrome, create partition starting from index+1
        vector<vector<bool>> dp = createPalindromePartitionMatrix(s);
        vector<vector<string>> result;
        vector<string> buffer;

        backtrack(s, dp, 0, buffer, result);
        return result;
    }
};

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }

    void backtracking(string s, int start, vector<string>& buff, vector<vector<string>>& result){
        if(start == s.size()){
            result.push_back(buff);
            return;
        }

        for(int end=start; end<s.size(); ++end){
            if(isPalindrome(s, start, end)){
                buff.push_back(s.substr(start, end-start+1));
                backtracking(s, end+1, buff, result);
                buff.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>buff;
        backtracking(s, 0, buff, result);
        return result;
    }
};