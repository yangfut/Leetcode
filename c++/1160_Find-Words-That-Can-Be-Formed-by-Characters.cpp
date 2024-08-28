class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count[26] = {0};
        for(const char &c : chars){
            count[c-'a']++;
        }

        int ans = 0;

        for(string &word : words){
            int temp_count[26] = {0};
            bool isGood = true;
            for(const char &c : word){
                temp_count[c-'a']++;
            }

            for(int i = 0; i < 26; ++i){
                if(temp_count[i] > count[i]){
                    isGood = false;
                    break;
                }
            }

            if(isGood){
                ans += word.length();
            }
        }
        return ans;
    }
};