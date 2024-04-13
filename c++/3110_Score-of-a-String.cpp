class Solution {
public:
    int scoreOfString(string s) {
        int prevIdx=0, score=0;
        
        for(int curIdx=1;curIdx<s.length();++curIdx){
            score+=abs(s[curIdx]-s[prevIdx]);
            prevIdx=curIdx;
        }
        return score;
    }
};