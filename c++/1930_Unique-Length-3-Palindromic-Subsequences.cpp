class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char, int> firstOccurence, lastOccurence;
        for(int i = 0; i < s.length(); ++i){
            if(firstOccurence.find(s[i]) == firstOccurence.end()){
                firstOccurence[s[i]] = i;
            }
            lastOccurence[s[i]] = i;
        }

        int ans = 0;
        for(const auto &it : firstOccurence){
            char c = it.first;
            int st = it.second, ed = lastOccurence[c];
            if(st == ed) continue;

            unordered_set<char> uniqueChar;
            for(int i = st+1; i < ed; ++i) uniqueChar.insert(s[i]);
            ans += uniqueChar.size();
        }
        return ans;
    }
};