class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.size() < 2) return sentence.front() == sentence.back();
        for(int i = 1; i < sentence.size(); ++i){
            if(sentence[i] != ' ') continue;
            if(sentence[i-1] != sentence[i+1]) return false;
        }
        return sentence.front() == sentence.back();
    }
};