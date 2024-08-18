class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int ptr = s.length()-1; ptr >= 0; --ptr){
            if(s[ptr] == ' ') continue;

            int length_count = 0;
            while(ptr >=0 && s[ptr] != ' '){
                ++length_count;
                --ptr;
            }
            return length_count;
        }
        // should never be here
        return -1;
    }
};