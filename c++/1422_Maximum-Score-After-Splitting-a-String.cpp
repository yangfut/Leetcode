class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, score = 0;
        for(char c : s){
            if(c == '1') ones++;
        }

        for(int i = 0; i < s.length()-1; ++i){
            if(s[i] == '1') --ones;
            if(s[i] == '0') ++zeros;

            score = max(ones+zeros, score);
        }
        return score;
    }
};