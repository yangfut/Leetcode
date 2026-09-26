class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReachFrom(n+1);
        for(int i = 0; i <= n; ++i){
            int l = max(0,i - ranges[i]);
            int r = min(n,i + ranges[i]);
            // This step is to simulate Jump Game II
            maxReachFrom[l] = max(maxReachFrom[l], r);
        }

        int farthest = 0, curr_end = 0, tap = 0;
        for(int i = 0; i <= n; ++i){
            if(i > curr_end) return -1;

            farthest = max(farthest, maxReachFrom[i]);

            if(i == curr_end){
                ++tap;
                curr_end = farthest;
                if(curr_end >= n) return tap;
            }
        }
        return -1;
    }
};