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

class Solution {
public:
    class TrieNode{
    public:
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode(){
            isEndOfWord = false;
            for(int i=0; i<26; ++i) children[i]=nullptr;
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(), idx = 0;
        TrieNode* root = new TrieNode();

        for(const string& word : wordDict){
            TrieNode* curr = root;
            for(const char& c:word){
                if(!curr->children[c-'a']) curr->children[c-'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->isEndOfWord = true;
        }
        vector<bool> memo(n, true);
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int st = que.front(); que.pop();
            if(!memo[st]) continue; // The visited starting point
            if(st == n) return true;
            TrieNode* curr = root;
            // search in root
            for(int i = st; i < s.length(); ++i){
                if(!curr->children[s[i]-'a']) break;

                curr = curr->children[s[i]-'a'];
                if(curr->isEndOfWord) que.push(i+1);
            }
            memo[st] = false; //Impossible to reach the end from this starting point
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordBank(wordDict.begin(), wordDict.end());
        set<int> wordSizes;
        vector<bool>dp(s.length(), false);
        for(const string word : wordDict) wordSizes.insert(word.size());

        for(int st=0; st<s.length(); ++st){
            for(const auto& len : wordSizes){
                if(wordBank.count(s.substr(st, len)) && (st==0||dp[st-1])){
                    dp[st+len-1] = true;
                }
            }
        }
        return dp.back();
    }
};