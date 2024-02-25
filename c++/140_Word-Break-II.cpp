#include <string>
#include <set>
#include <vector>

class Solution {
public:
    void workdBreak_recursive(string s, int st, unordered_set<string>& setDict, vector<string> &buff, vector<string> &res) {
        if(st==s.size()) {
            string sentence=buff[0];
            for(int i=1; i<buff.size();i++){
                sentence+=" ";
                sentence+=buff[i];
            }
            res.push_back(sentence);
            return;
        }
        for(int strlen=1; strlen<=s.size()-st; strlen++){
            string subStr=s.substr(st, strlen);
            if(setDict.find(subStr)==setDict.end()) continue;

            //Sub string maps setDict
            buff.push_back(subStr);
            workdBreak_recursive(s, st+strlen, setDict, buff, res);
            buff.pop_back();            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        vector<string>buff;
        unordered_set<string> setDict(wordDict.begin(), wordDict.end());
        workdBreak_recursive(s, 0, setDict, buff, res);
        return res;
    }
};