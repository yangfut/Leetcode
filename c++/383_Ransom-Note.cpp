class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;

        int freqCount[26];
        for(char& c : magazine) ++freqCount[c-'a'];
        for(char& c : ransomNote) {
            --freqCount[c-'a'];
            if(freqCount[c-'a'] < 0) return false;
        }
        return true;
    }
};