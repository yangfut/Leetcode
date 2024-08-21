class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> char_map;
        unordered_set<char> dup;

        for(int i = 0; i < s.length(); ++i){
            char c_s = s[i];
            char c_t = t[i];

            if(!char_map.count(c_s)){
                char_map[c_s] = c_t;
                if(dup.count(c_t)) return false;
                dup.insert(c_t);
            }else{
                if(char_map[c_s] != c_t) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        // initial value is zero
        int map_s[256];
        int map_t[256];

        for(int i = 0; i < s.length(); ++i){
            if(map_s[s[i]] != map_t[t[i]]) return false;

            // Don't use i because the initial value of array is zero.
            // It looks like every character are mapped to zero-index by default
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
};