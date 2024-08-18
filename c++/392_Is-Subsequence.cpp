class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()) return false;
        if(s.length() == 0) return true;

        for(int ptr_s = 0, ptr_t = 0; ptr_t < t.length(); ++ptr_t){

            if(s[ptr_s] == t[ptr_t]){
                ++ptr_s;
                if(ptr_s == s.length()) return true;
            }
        }
        return false;
    }
};