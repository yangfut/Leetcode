class Solution {
public:
    string reverseWords(string s) {
        // Left shift to remove extra spaces
        bool hasChar = false;
        int n = s.length();
        int leftShiftIndex = 0;
        for(int i = 0; i < n; ++i){
            if (!hasChar && s[i] == ' ') {
                ++leftShiftIndex;
                continue;
            }

            if(s[i] != ' ') hasChar = true;
            else hasChar = false;


            if(leftShiftIndex > 0){
                s[i-leftShiftIndex] = s[i];
            }
        }

        while(leftShiftIndex > 0 || s.back() == ' ') {
            s.pop_back();
            --leftShiftIndex;
        }

        // Reverse every single characters
        n = s.length();
        for(int i = 0; i < (n/2); ++i) swap(s[i], s[n-1-i]);

        // Revser every single words
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && s[j] != ' ') ++j;
            for(int k = 0; k < (j-i)/2; ++k) swap(s[i+k], s[j-1-k]);
            ++j;
        }
        return s;
    }
};