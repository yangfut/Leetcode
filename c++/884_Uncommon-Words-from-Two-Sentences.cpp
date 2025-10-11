class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freqCount;
        s1 += " ";
        s2 += " ";
        for(int st = 0, ed = 0; st < s1.length() && ed < s1.length(); ed++){
            if(s1[ed] == ' '){
                ++freqCount[s1.substr(st, ed-st)];
                st = ed+1;
            }
        }

        for(int st = 0, ed = 0; st < s2.length() && ed < s2.length(); ed++){
            if(s2[ed] == ' '){
                ++freqCount[s2.substr(st, ed-st)];
                st = ed+1;
            }
        }

        vector<string> res;
        for(auto& p : freqCount){
            if(p.second == 1) res.push_back(p.first);
        }
        return res;
    }
};