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

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length() + word2.length();
        int i = 0, j = 0, k = 0;
        string res;
        while(i < n){
            
            if(j < word1.length()){
                res += word1[j++];
                ++i;
            }

            if(k < word2.length()){
                res += word2[k++];
                ++i;
            }
        }
        return res;
    }
};