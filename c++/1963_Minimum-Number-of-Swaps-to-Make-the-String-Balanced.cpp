class Solution {
public:
    // "[[[]]]" -> 0
    int minSwaps(string s) {
        int left_open = 0;
        for(char &c : s){
            if(c == '[') left_open++;
            if(c == ']' && left_open) left_open--;
        }
        return (left_open+1)/2;
    }
};