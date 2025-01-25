class Solution {
    bool isPalindrome(string &s){
        int ll = 0, rr = s.length()-1;

        while(ll <= rr){
            if(s[ll] != s[rr]) return false;
            ++ll;
            --rr;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string &s : words){
            if(isPalindrome(s)) return s;
        }

        return string();
    }
};