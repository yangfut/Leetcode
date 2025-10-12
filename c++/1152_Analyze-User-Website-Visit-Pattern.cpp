class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<tuple<int,string,string>> log;
        unordered_map<string, vector<string>> record;
        unordered_map<string, int> patternCount;
        int n = username.size();
        for(int i = 0; i < n; ++i){
            log.emplace_back(timestamp[i], username[i], website[i]);
        }

        sort(log.begin(), log.end());
        for(auto& [t, currUser, currWeb]: log){
            if(!record.count(currUser)) record[currUser] = {};
            record[currUser].push_back(currWeb);
        }
        
        // Count pattern
        for(auto& [currUser, patterns] : record){
            int m = patterns.size();
            unordered_set<string> seen;
            for(int i = 0; i < m-2; ++i){
                for(int j = i+1; j < m-1; ++j){
                    for(int k = j+1; k < m; ++k){
                        seen.insert(patterns[i] + '#' + patterns[j] + '#' + patterns[k] + '#');
                    }
                }
            }

            for(auto& p : seen){
                ++patternCount[p];
            }
        }

        int maxOccurrence = 0;
        string bestPattern;
        for(auto& [currPattern, count] : patternCount){
            // lexicographically order
            if(count > maxOccurrence || (count == maxOccurrence && currPattern < bestPattern)){
                bestPattern = currPattern;
                maxOccurrence = count;
            }
        }
        vector<string> ans;
        for(int i = 0, j = 0; i < bestPattern.length() && j < bestPattern.length(); ++j){
            if(bestPattern[j] == '#'){
                // substr(index, length)
                ans.push_back(bestPattern.substr(i, j-i));
                i = j+1;
            }
        }
        return ans;

    }
};