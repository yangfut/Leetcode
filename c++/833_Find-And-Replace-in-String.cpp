class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // handle duplicates in indices
        unordered_map<int, vector<pair<string,string>>> replaceStrings;

        for(int i = 0; i < indices.size(); ++i){
            replaceStrings[indices[i]].push_back({sources[i], targets[i]});
        }

        string output;
        for(int i = 0; i < s.length(); ++i){
            int prev_output_len = output.length();

            if(replaceStrings.count(i)){
                for(auto& p : replaceStrings[i]){
                    int source_len = p.first.length();
                    if(s.substr(i, source_len) == p.first){
                        output += p.second;
                        i += (source_len - 1);
                        break;
                    }
                }
            }

            // none of sources matches or invalid index for indices
            if(prev_output_len == output.length()){
                output += s[i];
            }

        }
        return output;

    }
};