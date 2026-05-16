class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length(), cnt = 0;
        if(abs(n - m) > 1) return false;

        // Replace
        if(n == m){
            for(int i = 0; i < n; ++i){
                if(s[i] != t[i]) ++cnt;
            }
            if(cnt == 1) return true;
        }

        // Insert
        if(m - n == 1){
            cnt = 0;
            for(int i = 0, j = 0; i < n && j < m; ++i, ++j){
                if(s[i] != t[j]) {
                    ++cnt;
                    --i;
                }
            }

            if(cnt <= 1) return true;
        }
        // Delete
        if(n - m == 1){
            cnt = 0;
            for(int i = 0, j = 0; j < m && i < n; ++i, ++j){
                if(s[i] != t[j]){
                    ++cnt;
                    --j;
                }

            }

            if(cnt <= 1) return true;
        }
        return false;
    }
};