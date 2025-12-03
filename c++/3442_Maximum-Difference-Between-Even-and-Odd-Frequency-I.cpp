class Solution {
public:
    int maxDifference(string s) {
        int freq[26];
        for(char& c : s){
            ++freq[c-'a'];
        }
        int maxOddFreq = 1;
        int minEvenFreq = 101;

        for(int i = 0; i < 26; ++i){
            if(freq[i] == 0) continue;
            if(freq[i] % 2 == 0 && freq[i] < minEvenFreq) minEvenFreq = freq[i];
            else if (freq[i] % 2 == 1 && freq[i] > maxOddFreq) maxOddFreq = freq[i];
        }

        return maxOddFreq - minEvenFreq;
    }
};