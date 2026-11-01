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