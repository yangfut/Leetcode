class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 1. If no repeating char, ++right
        // 2. If found repeating char on right index, remove s[left] in set and ++left until no repeating element in set
        // 3. Keep doing this until right reach n(size of s)
        if(s.size()==0) return 0;

        int l=0, r=0, len=0, n=s.size();
        // set<char>st;
        vector<int> hash(255, 0);

        while(r<n){
            ++hash[s[r]];

            while(hash[s[r]]==2 && l<=r){
                --hash[s[l]];
                ++l;
            }

            len=max(len, r-l+1);
            ++r;
        }

        return len;
    }
};