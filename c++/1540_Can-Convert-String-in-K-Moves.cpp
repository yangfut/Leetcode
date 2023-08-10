class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;

        int n = s.size();
        int aChar, bChar, iMove, accMove, maxSteps;
        int alphaChart[26] = {0};

        for(int idx = 0; idx < n; idx++){
            aChar = s[idx];
            bChar = t[idx];
            if(bChar - aChar == 0) continue;
            iMove = bChar - aChar;
            if(iMove < 0) iMove+=26;
            ++alphaChart[iMove];
        }

        maxSteps = 0;

        for(int idx = 1; idx < 26; idx++){
            if(alphaChart[idx] == 0) continue;
            accMove = idx + 26*(alphaChart[idx]-1);
            if(maxSteps < accMove) maxSteps = accMove;
        }
        return (maxSteps > k ? false : true);
    }
};