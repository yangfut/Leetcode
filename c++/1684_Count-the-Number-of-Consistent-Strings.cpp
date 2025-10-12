class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int maskAllowed = 0;
        int numOfConsistentStr = 0;
        for(char& c : allowed) maskAllowed |= 1 << (c-'a');
        for(string& s : words){
            bool isConsistent = true;
            int maskWord = 0;
            for(char&c : s) maskWord |= 1 << (c-'a');
            if((maskWord & maskAllowed) == maskWord) ++numOfConsistentStr;
        }

        return numOfConsistentStr;
    }
};