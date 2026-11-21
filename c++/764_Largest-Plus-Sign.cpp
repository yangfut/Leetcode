class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> up(n, vector<int>(n,0));
        vector<vector<int>> down(n, vector<int>(n,0));
        unordered_set<int> m;
        for(int i = 0; i < mines.size(); ++i){
            int x = mines[i][0];
            int y = mines[i][1];
            m.insert(x*n+y);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int hash = i*n+j;
                if(m.count(hash)) continue;
                int prev = (i == 0) ? 0 : up[i-1][j];
                up[i][j] = prev + 1;
            }
        }

        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                int hash = i*n+j;
                if(m.count(hash)) continue;
                int prev = (i == n-1) ? 0 : down[i+1][j];
                down[i][j] = prev + 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            vector<int> left(n,0);
            for(int j = 0; j < n; ++j){
                int hash = i*n+j;
                if(m.count(hash)) continue;
                int prev = (j == 0) ? 0 : left[j-1];
                left[j] = prev + 1;
            }

            vector<int> right(n,0);
            for(int j = n-1; j >= 0; --j){
                int hash = i*n+j;
                if(m.count(hash)) continue;
                int prev = (j == n-1) ? 0 : right[j+1];
                right[j] = prev + 1;
            }
            for(int j = 0; j < n; ++j){
                // cout << i << " " << up[i][j] << " " << left[j]  << " " << right[j]  << " " << down[i][j] << endl;
                ans = max(ans, min({up[i][j], left[j], right[j], down[i][j]}));
            }
            // cout << endl;

        }
        return ans;

    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n,n));
        unordered_set<int> m;
        for(auto& m : mines) dp[m[0]][m[1]] = 0;

        for(int i = 0; i < n; ++i){
            // left to right
            int run = 0;
            for(int j = 0; j < n; ++j){
                run = (dp[i][j] == 0) ? 0 : run + 1;
                dp[i][j] = min(dp[i][j], run);
            }

            // right to left
            run = 0;
            for(int j = n-1; j >= 0; --j){
                run = (dp[i][j] == 0) ? 0 : run + 1;
                dp[i][j] = min(dp[i][j], run);
            }
        }

        for(int j = 0; j < n; ++j){
            // top to bottom
            int run = 0;
            for(int i = 0; i < n; ++i){
                run = (dp[i][j] == 0) ? 0 : run + 1;
                dp[i][j] = min(dp[i][j], run);
            }

            // bottom to top
            run = 0;
            for(int i = n-1; i >= 0; --i){
                run = (dp[i][j] == 0) ? 0 : run + 1;
                dp[i][j] = min(dp[i][j], run);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;

    }
};