class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for(char& c : s){
            if(c == t[j]) ++j;
        }

        return t.length() - j;
    }
};