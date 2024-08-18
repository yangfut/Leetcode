class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(int char_idx = 0; char_idx < strs[0].size(); ++char_idx){
            char c = strs[0][char_idx];
            for(int i = 0; i < strs.size(); ++i){
                if(char_idx == strs[i].length()) return strs[i];

                if(strs[i][char_idx] != c){
                    return strs[0].substr(0, char_idx);
                }
            }
        }

        // The entire strs[0] is common prefix
        return strs[0];
    }
};