class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> collection;
        for(char& c : s) ++collection[c];
        int result = 0, isOdd = 0;
        for(auto [_, num]: collection){
            if(num % 2 == 1){
                result += (num-1);
                isOdd = 1;
            }else result += num;
        }

        return result + isOdd;
    }
};