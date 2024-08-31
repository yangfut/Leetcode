class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> collection;
        for(auto &p : paths) collection.insert(p[0]);
        for(auto &p : paths){
            if(!collection.count(p[1])) return p[1];
        }
        // should never be here
        return "";
    }
};