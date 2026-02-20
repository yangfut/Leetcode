class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int dist = INT_MAX;
        int idx1 = -1, idx2 = -1;
        bool isSame = word1 == word2;
        for(int i = 0; i < wordsDict.size(); ++i){
            if(wordsDict[i] == word1) idx1 = i;
            if(wordsDict[i] == word2){
                if(isSame) idx1 = idx2;
                idx2 = i;
            }
            if(idx1 != -1 && idx2 != -1) dist = min(dist, abs(idx1 - idx2));
        }
        return dist;
    }
};

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size(), dist = INT_MAX;
        if(word1 == word2){
            int prev = -1;
            for(int i = 0; i < n; ++i){
                if(wordsDict[i] == word1){
                    if(prev != -1){
                        dist = min(dist, i - prev);
                    }
                    prev = i;
                }
            }
            return dist;
        }
        int idx1 = -1, idx2 = -1;
        for(int i = 0; i < n; ++i){
            if(wordsDict[i] == word1) idx1 = i;
            if(wordsDict[i] == word2) idx2 = i;

            if(idx1 != -1 && idx2 != -1) dist = min(dist, abs(idx1 - idx2));
        }
        return dist;
    }
};