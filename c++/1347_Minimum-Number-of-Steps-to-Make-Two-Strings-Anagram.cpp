class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> alpha(26, 0);
        for(char c:s) alpha[c-'a']++;
        for(char c:t) alpha[c-'a']--;

        int count=0;
        for(int i=0;i<26;i++) count +=abs(alpha[i]);
        return count/2;
    }
};