class WordDistance {
public:
    unordered_map<string, vector<int>> wordIndex;
    WordDistance(vector<string>& wordsDict) {
        int n = wordsDict.size();
        for(int i = 0; i < n; ++i){
            string& s = wordsDict[i];
            wordIndex[s].emplace_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& vec1 = wordIndex[word1];
        vector<int>& vec2 = wordIndex[word2];
        int dist = INT_MAX;
        int i = 0, j = 0, n = vec1.size(), m = vec2.size();
        while(i < n && j < m){
            dist = min(abs(vec1[i] - vec2[j]), dist);
            if(vec1[i] < vec2[j]) ++i;
            else ++j;
        }
        return dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */