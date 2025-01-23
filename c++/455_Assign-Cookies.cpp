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

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gIndex = 0, sIndex = 0, gSize = g.size(), sSize = s.size(), res = 0;
        while(sIndex < sSize && gIndex < gSize){

            if(s[sIndex] >= g[gIndex]){
                ++gIndex;
                ++res;
            }
            ++sIndex;
        }
        return res;  
    } 
};