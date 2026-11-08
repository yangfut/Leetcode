class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        string d1, d2;
        for(int i = 0; i < n; ++i){
            if(s1[i] == s2[i] && d1.empty()) continue;
            else if(s1[i] == s2[i] && !d1.empty()){
                ans.push_back({d1,d2});
                d1.clear();
                d2.clear();
            }else{
                d1 += s1[i];
                d2 += s2[i];
            }
        }
        if(!d1.empty()) ans.push_back({d1,d2});
        return ans;
    }
};