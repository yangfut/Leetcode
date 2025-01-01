//Time: Beats 41%, Space: Beats 51%
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<vector<int>> table(26, vector<int>(26, 0));
        int hit_mask = 0;
        unordered_set<string> appear;
        for(string &s : ideas){
            int firstChar = s[0] - 'a';
            appear.insert(s);
            hit_mask |= 1 << firstChar;
        }
        
        for(string &s : ideas){
            char org = s[0];
            for(char c = 'a'; c <= 'z'; ++c){
                if(hit_mask & (1 << c-'a') == 0) continue;

                s[0] = c;
                if(appear.count(s)) continue;

                table[org-'a'][c-'a'] += 1;
            }
            s[0] = org;
        }
        long long count = 0;
        for(string &s : ideas){
            char org = s[0];
            for(char c = 'a'; c <= 'z'; ++c){
                if(hit_mask & (1 << c-'a') == 0) continue;

                s[0] = c;
                if(appear.count(s)) continue;

                count += table[c-'a'][org-'a'];
            }
        }
        return count;
    }
};

//Time: Beats 81%, Space: 80%
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> groups(26);
        long long count = 0;
        for(const string &s : ideas){
            int firstChar = s[0]-'a';
            string suffix = s.substr(1);
            groups[firstChar].insert(suffix);
        }

        for(int i = 0; i < 26; ++i){
            for(int j = i+1; j < 26; ++j){
                int mutualSuffix = 0;

                for(const auto it : groups[j]){
                    if(groups[i].count(it)) ++mutualSuffix;
                }

                long long uniqueI = groups[i].size() - mutualSuffix;
                long long uniqueJ = groups[j].size() - mutualSuffix;
                
                count += 2LL * uniqueI * uniqueJ;
            }
        }

        return count;
        
    }
};