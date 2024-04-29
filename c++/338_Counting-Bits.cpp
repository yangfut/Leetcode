class Solution {
public:
    vector<int> countBits(int n) {
        

        // #1 bitset
        // vector<int> result(n+1);
        // for(int i=0; i<=n; ++i){
        //     bitset<32>bit(i);
        //     result[i] = bit.count();
        // }
        // return result;

        // #2 bit operation
        // BY OBSERVATION:
        // dp[2] = 1 + dp[0];
        // dp[3] = 1 + dp[1];
        // dp[4] = 1 + dp[0];
        // dp[5] = 1 + dp[1];
        // dp[6] = 1 + dp[2];

        vector<int> dp(n+1);
        if(n == 0) return dp;
        dp[1] = 1;

        for(int powerOfTwo = 2; powerOfTwo < 100001; powerOfTwo*=2){
            if(powerOfTwo > n) return dp;

            int i = 0;
            while(powerOfTwo + i < powerOfTwo * 2 && powerOfTwo + i <= n){
                dp[powerOfTwo+i] = 1 + dp[i];
                ++i;
            }
        }

        // should not be here
        return dp;
    }
};