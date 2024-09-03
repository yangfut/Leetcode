class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        // #1 Brute-force solution TC:O(N^2), SC:O(1)
        // int len = -1;
        // for(int i = 0; i < s.length(); ++i){
        //     for(int j = i; j < s.length(); ++j){
        //         if(s[i] == s[j]) len = max(j-i-1, len);
        //     }
        // }

        // #2 hash table
        int hash_table[26] = {0};
        int len = -2;
        for(int i = 0; i < s.length(); ++i){
            hash_table[s[i]-'a'] = i;
        }

        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            int j = hash_table[c-'a'];
            if(j != i) len = max(len, j-i-1);
        }

        return len == -2 ? -1 : len;
    }
};