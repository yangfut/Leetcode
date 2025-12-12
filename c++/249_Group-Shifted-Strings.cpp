class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, int> group;
        for(const string& s : strings) ++group[s];

        while(!group.empty()){
            auto it = group.begin();
            string curr = it->first;
            int count = it->second;
            vector<string> groupVec(count, curr);
            group.erase(group.begin());
            for(int i = 0; i < 25; ++i){
                for(char& c : curr){
                    // right shift each character
                    c = ((c-'a'+1)%26) + 'a';
                }

                auto f = group.find(curr);
                if(f != group.end()){
                    for(int j = 0; j < f->second; ++j){
                        groupVec.emplace_back(curr);
                    }
                    group.erase(curr);
                }
            }
            res.emplace_back(groupVec);
        }
        return res;
    }
};