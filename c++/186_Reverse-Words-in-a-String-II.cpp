class Solution {
public:
    void reverseWords(vector<char>& s) {
        // Reverse all characters
        int n = s.size();
        for(int i = 0; i < n/2; ++i) swap(s[i], s[n-1-i]);

        // Reverse every single words
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && s[j] != ' ') ++j;
            for(int k = 0; k < (j-i)/2; ++k) swap(s[i+k], s[j-1-k]);
            ++j;
        }
    }
};