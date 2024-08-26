class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // Use map to map pattern and word
        unordered_map<char, string> map;

        // Use set to avoid multiple pattern mapping to the same word
        unordered_set<string> set_appeared;

        int s_idx = 0, c_idx = 0;

        // Consider the boundary of pattern and s
        // Mismatch happens if s_idx reachs to the end, but c_idx still there
        while(c_idx < pattern.length() && s_idx < s.length()){
            char c = pattern[c_idx];
            int st = s_idx;
            while(s_idx < s.length() && s[s_idx] != ' ') ++s_idx;

            string word = s.substr(st, s_idx-st);

            if(map.count(c)){
                if(map[c] != word) return false;
            }else{
                // check word is unique, which means it's not in the value of map
                if(set_appeared.count(word)) return false;
                map[c] = s.substr(st, s_idx-st);
                set_appeared.insert(word);
            }

            ++s_idx;
            ++c_idx;
        }

        return s_idx == s.length()+1 && c_idx == pattern.length();
    }
};