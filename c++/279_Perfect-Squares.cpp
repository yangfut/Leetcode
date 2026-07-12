// Tabulation DP
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        // dp = {1,1,1,1}
        for(int i = 1; i <= n; ++i){
            // 1,2,3,4
            for(int j = 1; j*j <= n; ++j){
                // 1, 4
                int val = j*j;
                // 4 >? 4
                if(val > i) break;

                // dp[4] = min(INT_MAX, dp[3]) = 1
                dp[i] = min(dp[i], 1+dp[i - val]);
            }
        }
        return dp[n];
    }
};

// BFS
class Solution {
public:
    int numSquares(int n) {
        vector<int> visited(n+1,0);
        int cnt = 0;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            ++cnt;
            int qs = q.size();
            for(int i = 0; i < qs; ++i){
                int val = q.front(); q.pop();
                for(int k = 1; k*k <= val; ++k){
                    int nxt = val - (k*k);
                    if(nxt == 0) return cnt;
                    if(visited[nxt] == 1) continue;
                    visited[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
        // should not be here
        return -1;
    }
};