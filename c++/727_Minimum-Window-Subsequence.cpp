class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n < m) return "";
        int wlhs = -1, wrhs = -1;
        for(int lhs = 0; lhs < n; ++lhs){
            if(s1[lhs] != s2[0]) continue;
            int rhs = lhs, k = 0;
            while(rhs < n && k < m){
                if(s1[rhs] == s2[k]) ++k;
                if(k == m) break;
                ++rhs;
            }

            if(k == m){
                if(wlhs == -1 || (rhs - lhs) < (wrhs - wlhs)){
                    wlhs = lhs;
                    wrhs = rhs;
                }
            }
        }

        return wlhs == -1 ? "" : s1.substr(wlhs, wrhs - wlhs + 1);
    }
};

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n < m) return "";
        int wlhs = -1, wrhs = -1;
        for(int lhs = 0; lhs < n; ++lhs){
            if(s1[lhs] != s2[0]) continue;
            // Two-pass sliding window - first pass
            int rhs = lhs, k = 0;
            while(rhs < n && k < m){
                if(s1[rhs] == s2[k]) ++k;
                if(k == m) break;
                ++rhs;
            }

            if(k != m) break;
            // Two-pass sliding window - second pass
            --k;
            lhs = rhs;
            while(lhs >= 0 && k >= 0){
                if(s1[lhs] == s2[k]) --k;
                if(k < 0) break;
                --lhs;
            }
            if(k < 0){
                if(wlhs == -1 || (rhs - lhs) < (wrhs - wlhs)){
                    wrhs = rhs;
                    wlhs = lhs;
                }
            }
        }
        return (wlhs == -1) ? "" : s1.substr(wlhs, wrhs - wlhs + 1);
    }
};