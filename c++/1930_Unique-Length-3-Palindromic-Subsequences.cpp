class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char, int> countPalindrom;
        int l = s.length();
        for(int i = 0; i < l; ++i){
            char c = s[i];
            if(countPalindrom.find(c) != countPalindrom.end()) continue;

            for(int j = l-1; j > i; --j){
                if(s[j] != c) continue;
                
                unordered_set<char> unique;
                for(int k = i+1; k < j; ++k) unique.insert(s[k]);
                countPalindrom[c] = unique.size();
                break;
            }
        }
        int ans = 0;
        for(auto &it : countPalindrom) ans += it.second;
        return ans;
    }
};