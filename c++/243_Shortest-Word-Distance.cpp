class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int dist = INT_MAX;
        int idx1 = -1, idx2 = -1;
        for(int i = 0; i < wordsDict.size(); ++i){
            if(wordsDict[i] == word1){
                idx1 = i;
                if(idx2 != -1) dist = min(dist, idx1 - idx2);
            }

            if(wordsDict[i] == word2){
                idx2 = i;
                if(idx1 != -1) dist = min(dist, idx2 - idx1);
            }
        }

        return dist;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int dist = INT_MAX;
        int idx1 = -1, idx2 = -1;
        for(int i = 0; i < wordsDict.size(); ++i){
            if(wordsDict[i] == word1) idx1 = i;
            if(wordsDict[i] == word2) idx2 = i;
            if(idx1 != -1 && idx2 != -1) dist = min(dist, abs(idx1 - idx2));
        }
        return dist;
    }x
};
