class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        // 1. Greedy: find the maximum value for each element
        int n = strs.size();
        vector<string> transformed(n);
        for(int i = 0; i < n; ++i){
            string org = strs[i];
            string rev = org;
            reverse(rev.begin(), rev.end());

            if(rev > org) transformed[i] = rev;
            else transformed[i] = org;
        }

        string ans = "";
        // 2. Greedy: pick up an element and check if it's valid for original or revered order
        for(int i = 0; i < n; ++i){
            string org = transformed[i];
            string rev = org;
            reverse(rev.begin(), rev.end());
            string middle = "";
            for(int j = i+1; j < n; ++j) middle += transformed[j];
            for(int j = 0; j < i; ++j) middle += transformed[j];

            
            // 3. Find proper cut-point for each place in the current string. Consider reversed version because
            // the overall value is impacted when adding middle
            for(const string& curr : {org, rev}){
                for(int k = 0; k < curr.length(); ++k){
                    // skip if ans has greater lexicographic value
                    if(!ans.empty() && ans[0] > curr[k]) continue;
                    string candidate = curr.substr(k) + middle + curr.substr(0, k);
                    if(candidate > ans) ans = candidate;
                }
            }

        }
        return ans;
    }
};