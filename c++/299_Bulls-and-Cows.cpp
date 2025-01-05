class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int countA = 0, countB = 0;
        int secFreq[10] = {0};
        int gusFreq[10] = {0};

        for(int i = 0; i < n; ++i){
            
            char secNum = secret[i];
            char gusNum = guess[i];

            if(secNum == gusNum) ++countA;
        
            secFreq[secNum - '0']++;
            gusFreq[gusNum - '0']++;
        }

        for(int i = 0; i < 10; ++i){
            countB += min(secFreq[i], gusFreq[i]);
        }

        countB -= countA;
        return to_string(countA) + 'A' + to_string(countB) + 'B';
    }
};