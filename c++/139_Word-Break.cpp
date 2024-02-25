class Solution {
public:
    bool workBreak_solution(string s, unordered_set<string>& setDict) {
        if(0==s.size()) return true;

        for(int ed=0;ed<s.size();ed++){
            string subStr=s.substr(0, ed+1);
            if(setDict.count(subStr) && workBreak_solution(s.substr(ed+1), setDict)) return true;
        }
        return false;
    }

    bool tabulation_solution(string s, unordered_set<string>& setDict) {
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        
        for(int i=1; i<=s.size();i++){
            //To determine dp[i], find dp[j]==true and substr(j, i-j) exists in setDict
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    if(setDict.count(s.substr(j, i-j))){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
    bool tabulation_2_solution(string s, vector<string>& wordDict){
        vector<bool>dp(s.size()+1, false);
        dp[0]=true;
        for(int i=1; i<=s.size();i++){
            for(string word:wordDict){
                if(i>=word.size() && dp[i-word.size()]&& s.substr(i-word.size(),word.size())==word){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        //#1 Backtracking + Hash Table
        //TC:O(N!+M), SC:O(M)
        //unordered_set<string>setDict(wordDict.begin(), wordDict.end());
        //return workBreak_solution(s, setDict);

        //#2 Tabulation for DP(Set)
        //TC:O(N^2+M), SC:O(N+M)
        //unordered_set<string>setDict(wordDict.begin(), wordDict.end());
        //return tabulation_solution(s, setDict);

        //#3 Tabulation for DP(Optimized)
        //TC:(NM), SC:(N)
        return tabulation_2_solution(s, wordDict);

    }
};