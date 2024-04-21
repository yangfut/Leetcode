
// DP with Binary Search
// Beats 5% in runtime and 5% in memory
class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b){
        return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
    }

    int BinarySearchToFindBefore(int value, vector<vector<int>>& offers){
        // use binary search to find the index before value in the offers
        int l = 0, r = offers.size();
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(offers[mid][1] < value){
                l = mid+1;
                ans = mid;
            }else r = mid-1;
        }
        return ans;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // sort by offers[1]
        sort(offers.begin(), offers.end(), cmp);

        int m = offers.size(); 
        vector<int> dp(m, 0); // dynamic programming for offers
        vector<int> pfmx(m, 0); // accumulate maximum profit

        for(int k = 0; k < m; ++k){

            int idx = BinarySearchToFindBefore(offers[k][0], offers);
            
            // store the maximum profit earned by the current offer
            dp[k] = (idx == -1) ? offers[k][2] : pfmx[idx] + offers[k][2];
            pfmx[k] = (k) ? max(pfmx[k-1], dp[k]) : dp[k];
        }
        return pfmx.back();
    }
};

// Naive DP solution
// Beats 5% in runtime and 8% in memory
class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b){
        return a[1] < b[1];
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        if(offers.empty()) return 0;

        vector<int> dp(n, 0);
        // sort by offers[1]
        sort(offers.begin(), offers.end(), cmp);
        
        int maxv = dp[0];
        int m = offers.size();
        int idx = 0;
        for(int k = 0; k < m; ++k){
            int ed = offers[k][1];
            while(idx < ed){
                dp[idx++] = maxv;
            }

            int st = offers[k][0], gold = offers[k][2];
            if(st == 0) dp[ed] = max(maxv, gold);
            else dp[ed] = max(maxv, gold + dp[st-1]);

            if(dp[ed] > maxv) maxv = dp[ed];
        }
        return maxv;
    }
};