class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans;
        vector<char>temp(s.size());
        for(int i=0;i<s.size();++i) temp[indices[i]]=s[i];
        for(char c:temp) ans+=c;
        return ans;
    }
};