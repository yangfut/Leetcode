class Solution {
public:
    int minimumLength(string s) {
        int freq[26], len = 0;
        for(char c : s) ++freq[c-'a'];
        for(int f : freq){
            if(f < 3) len += f;
            else if(f % 2 == 0) len += 2;
            else len += 1;
        }
        return len;
    }
};