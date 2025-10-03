class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int charFreq[26];
        for(int i = 0; i < 26; ++i) charFreq[i] = INT_MAX;

        int n = words.size();
        for(string& word : words){
            int tempCharFreq[26] = {0};
            for(char& c : word){
                ++tempCharFreq[c-'a'];
            }

            for(int i = 0; i < 26; ++i){
                charFreq[i] = min(charFreq[i], tempCharFreq[i]);
            }
        }

        vector<string> res;
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < charFreq[i]; ++j){
                string singleChar(1, char(i+'a'));
                res.push_back(string(singleChar));
            }
        }
        return res;
    }
};