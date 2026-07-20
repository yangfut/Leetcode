class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int ones = 0;
        for(char c : s) if(c == '1') ++ones;
        for(int i = 0; i < n; ++i) s[i] = '0';
        for(int i = 0; ones > 1; ++i, --ones) s[i] = '1';
        s.back() = '1';
        return s;
    }
};