class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ptrS = s.length() - 1;
        int ptrT = t.length() - 1;
        int skipS = 0, skipT = 0;

        while(ptrS>=0 || ptrT>=0){

            while(ptrS>=0 && s[ptrS] == '#'){
                --ptrS;
                ++skipS;
                while(ptrS>=0 && s[ptrS] != '#' && skipS){
                    --skipS;
                    --ptrS;
                }
            }

            while(ptrT>=0 && t[ptrT] == '#'){
                --ptrT;
                ++skipT;
                while(ptrT >=0 && t[ptrT] != '#' && skipT){
                    --skipT;
                    --ptrT;
                }
            }

            if(ptrS < 0 && ptrT < 0) return true;
            else if(ptrS < 0 || ptrT < 0) return false;
            else if(s[ptrS] != t[ptrT]) return false;

            --ptrS;
            --ptrT;
        }
        return true;
    }
};