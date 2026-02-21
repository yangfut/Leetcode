class Solution {
public:
    string replaceWithKey(string& val, unordered_map<string,string>& wordMap){
        if(val.find('%') == string::npos) return val;
        string output;
        int n = val.size(), idx = 0;
        while(idx < n){
            if(val[idx] == '%'){
                string temp;
                ++idx;
                while(idx < n && val[idx] != '%'){
                    temp.push_back(val[idx]);
                    ++idx;
                }
                if(!wordMap.count(temp)) return "";
                output.append(wordMap[temp]);
            }else{
                output.push_back(val[idx]);
            }
            ++idx;
        }
        return output;
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> wordMap;
        queue<pair<string,string>> q;
        for(auto& p : replacements) q.push({p[0], p[1]});

        while(!q.empty()){
            auto& [key, val] = q.front(); 
            string resolved = replaceWithKey(val, wordMap);
            if(resolved.empty()) q.push({key, val});
            else wordMap[key] = resolved;
            q.pop();
        }
        return replaceWithKey(text, wordMap);
    }
};