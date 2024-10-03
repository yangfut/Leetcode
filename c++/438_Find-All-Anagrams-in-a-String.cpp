class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_mask = 0, p_mask = 0, n = s.length(), m = p.length();
        int p_count[26], s_count[26];
        for(char &c : p){
            p_count[c-'a']++;
            p_mask |= 1 << (c-'a');
        }
        
        for(int i = 0; i < n; ++i){
            if(i-m >= 0){
                int to_remove = s[i-m] -'a';
                --s_count[to_remove];
                
                // set bit to 0
                if(s_count[to_remove] < p_count[to_remove]){
                    if(s_mask & (1 << to_remove)) s_mask &= ~(1 << to_remove);
                }
            }

            int curr = s[i] - 'a';
            ++s_count[curr];

            // set bit to 1
            if(s_count[curr] == p_count[curr]) s_mask |= 1 << curr;
            if(s_mask == p_mask) ans.push_back(i-m+1);
        }
        return ans;
    }
};