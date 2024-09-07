class Solution {
public:
    int firstUniqChar(string s) {
        int hash_table[26] = {0};
        for(char &c : s) ++hash_table[c-'a'];
        for(int i = 0; i < s.length(); ++i){
            if(hash_table[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};