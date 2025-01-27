class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Size = word1.size(), word2Size = word2.size();
        int word1Idx = 0, char1Idx = 0;
        int word2Idx = 0, char2Idx = 0;

        while(word1Idx < word1Size && word2Idx < word2Size){
            
            char w1 = word1[word1Idx][char1Idx++];
            char w2 = word2[word2Idx][char2Idx++];

            if(w1 != w2) return false;

            int w1Size = word1[word1Idx].size();
            int w2Size = word2[word2Idx].size();
            
            if(char1Idx == w1Size){
                ++word1Idx;
                char1Idx = 0;
            }

            if(char2Idx == w2Size){
                ++word2Idx;
                char2Idx = 0;
            }
        }

        return (word1Idx == word1Size && word2Idx == word2Size) ? true : false;
    }
};