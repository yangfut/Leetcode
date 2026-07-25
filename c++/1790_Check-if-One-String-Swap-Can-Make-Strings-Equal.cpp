class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // one swap: (1) same char collection, (2) only two difference
        int d1 = -1, d2 = -1;
        int n = s1.length();
        for(int i = 0; i < n; ++i){
            if(s1[i] == s2[i]) continue;
            if(d1 == -1){
                d1 = i;
            }else if (d2 == -1){
                d2 = i;
            }else return false;
        }
        if(d1 == d2) return true;
        if(d2 == -1) return false;
        return s1[d1] == s2[d2] && s1[d2] == s2[d1];
    }
};