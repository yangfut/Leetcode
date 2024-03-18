#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string new_s="";
        for(char c:s){
            if(isalnum(c)) new_s.push_back(tolower(c));
        }
        
        int low=0, high=new_s.size()-1;
        while(low<=high){
            if(new_s[low]!=new_s[high]) return false;

            ++low;
            --high;
        }
        return true;
    }
};