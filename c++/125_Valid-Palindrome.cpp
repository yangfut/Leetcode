#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int idxA = 0;
        int idxB = s.size()-1;
        bool ans = true;

        while(idxB >= idxA){
            if(!isalnum(s[idxA])){
                idxA++;
                continue;
            }
            if(!isalnum(s[idxB])){
                idxB--;
                continue;
            }

            if(tolower(s[idxA]) == tolower(s[idxB])){
                idxB--;
                idxA++;
            }else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};