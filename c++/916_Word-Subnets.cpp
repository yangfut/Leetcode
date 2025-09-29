class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxFreq[26]={};
        vector<string> universalWords;
        for(string& s : words2){
            int wordFreq[26]={};
            for(char& c : s){
                wordFreq[c-'a'] += 1;
            }

            for(int i = 0; i < 26; ++i){
                if(maxFreq[i] < wordFreq[i]) maxFreq[i] = wordFreq[i];
            }
        }

        for(string& s : words1){
            int wordFreq[26]={};
            for(char& c : s){
                wordFreq[c-'a'] += 1;
            }

            bool is_universal = true;
            for(int i = 0; i < 26; ++i){
                if(maxFreq[i] > wordFreq[i]){
                    is_universal = false;
                    break;
                }
            }

            if(is_universal) universalWords.push_back(s);
        }
        return universalWords;
    }
};