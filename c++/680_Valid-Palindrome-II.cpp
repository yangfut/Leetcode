class Solution {
private:
    bool _valid(const string &s, int l, int len){
        int r = l + len - 1;
        while(l < r){
            if(s[l] != s[r]) return false;

            ++l;
            --r;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                if(_valid(s, l+1, r-l) || _valid(s, l, r-l)) return true;
                return false;
            }

            ++l;
            --r;
        }
        return true;
    }
};