class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int hash_table[26] = {0};

        for(const string &word : words){
            for(const char &c : word){
                hash_table[c-'a']++;
            }
        }
        int n = words.size();
        for(int i = 0; i < 26; ++i){
            if(hash_table[i] % n > 0) return false;
        }
        return true;
    }
};