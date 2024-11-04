class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = std::max(word1.size(), word2.size());
        string output;
        for(int i = 0; i < len; ++i){
            if(i < word1.size()){
                output += word1[i];
            }

            if(i < word2.size()){
                output += word2[i];
            }
        }
        return output;
    }
};