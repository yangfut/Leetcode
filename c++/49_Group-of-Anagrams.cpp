class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> newStrs(strs);
        unordered_map<string, vector<string>>dict;
        vector<vector<string>> res;
        for(int i=0;i<newStrs.size();i++) sort(newStrs[i].begin(), newStrs[i].end());

        for(int i=0;i<newStrs.size();i++) dict[newStrs[i]].push_back(strs[i]);

        for(auto pair:dict) res.push_back(pair.second);
        
        return res;
    }
};