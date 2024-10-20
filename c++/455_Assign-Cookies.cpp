class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());

        int n = g.size(), m = s.size(), cnt = 0;
        for(int i = 0, j = 0; i < n && j < m; ++i){
            if(s[j] >= g[i]){
                ++j;
                ++cnt;
            }
        }
        return cnt;
    }
};