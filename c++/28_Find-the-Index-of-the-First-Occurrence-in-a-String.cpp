class Solution {
public:
    int strStr(string haystack, string needle) {
        // Brute-force
        for(int i = 0; i < haystack.length(); ++i){
            if(haystack[i] != needle[0]) continue;
            for(int j = 0; j < needle.length(); ++j){
                if(haystack[i+j] != needle[j]) break;
                if(j == needle.length()-1 ) return i;
            }
        }

        return -1;
    }
};