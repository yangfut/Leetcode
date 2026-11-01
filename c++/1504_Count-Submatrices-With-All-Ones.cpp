/*
BF:
1. Enumerate every top-left and bottom-right pair and check that all cells are 1.
for r1, c1:
    for r2, c2:
        if all cells inside (r1,r2) and (c1,c2) are 1:
            cnt++

TC: O((MN)^3)

2. Use height array to accumulcate the consecutive cells in 1
for r:
    for c:
        if cell is 1: h[c]++

Q: How can we identify all the cells in this range is 1?
A: Achor the bottom-left cell and calculate left-edge, right-edge at least this tall

1 1
1 1
each such range holds h[c] rectangles

left-edge: 0-(-1) = 1
right-edge: 2-0 = 2
height = 2
count = 2 * 2 = 4

Actual rectangle including the achor cell: 2*1, 1*2, 1*1, 2*2
*/
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n,0);
        int cnt = 0;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(mat[r][c] == 0){
                    h[c] = 0;
                }else{
                    h[c] += 1;
                }
            }
            vector<int> nls(n,n);
            vector<int> pls(n,-1);
            stack<int> st;
            for(int c = 0; c < n; ++c){
                while(!st.empty() && h[c] < h[st.top()]) st.pop();
                if(!st.empty()) pls[c] = st.top();
                st.push(c);
            }

            while(!st.empty()) st.pop();

            for(int c = n-1; c >= 0; --c){
                while(!st.empty() && h[c] <= h[st.top()]) st.pop();
                if(!st.empty()) nls[c] = st.top();
                st.push(c);
            }

            for(int c = 0; c < n; ++c){
                cnt += (h[c] * (c - pls[c]) * (nls[c] - c));
            }
        }
        return cnt;
    }
};