class Solution {
public:
    int countSubstrings(string s) {
        // 1. Count palindrome in odd length
        // 2. Count palindrome in even length

        int numOfPalindrome=0, n=s.length();
        for(int center=0; center<n; ++center){
            int l=center, r=center;

            // for odd length
            while(r<n && l>=0 && s[r]==s[l]){
                ++numOfPalindrome;
                ++r;
                --l;
            }

            // for even length
            l=center, r=center+1;
            while(r<n && l>=0 && s[r]==s[l]){
                ++numOfPalindrome;
                ++r;
                --l;
            }
        }
        return numOfPalindrome;
    }
};