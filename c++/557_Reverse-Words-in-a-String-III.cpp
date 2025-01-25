class Solution {
    void reverseStr(string &s, int lhs, int rhs){
        
        while(lhs < rhs){
            swap(s[lhs], s[rhs]);
            ++lhs;
            --rhs;
        }
    }
public:
    string reverseWords(string s) {
        int lhs = -1, rhs = 0, n = s.length();
        while(rhs < n){
            if(s[rhs] == ' '){
                reverseStr(s, lhs+1, rhs-1);
                lhs = rhs;
            }
            ++rhs;
        }
        reverseStr(s, lhs+1, rhs-1);
        return s;
    }
};