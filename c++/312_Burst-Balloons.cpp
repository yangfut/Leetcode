class Solution {
public:
    int memoHelper(vector<int>& nums, int st, int ed, vector<vector<int>>& dp){
        // happens only when just one bulloon remains in that segment, so return invalud semgent(st>ed) to zero
        if(st > ed) return 0;

        // caching
        if(dp[st][ed] != -1) return dp[st][ed];
        
        // this bulloon is picked LAST.
        // To determine the bullon, we need to consider the result after picking this bulloon as the last one
        int maxCoins = 0;

        // At the first round, since this bulloon is picked last, so 1(nums[st-1]) * nums[k] * 1(nums[ed+1])
        // After the first round, "last bullon" nums[st-1] * "bulloon picked in this round" nums[k] * 1(nums[ed+1])
        for(int k = st; k <= ed; ++k){
            // memoHelper(nums, st, k-1, dp) and memoHelper(nums, k+1, ed, dp) represents both segments are connecting to the current bulloon in index k
            // This only happens when we take the current bulloon as the LAST one
            maxCoins = max(maxCoins, nums[st-1] * nums[k] * nums[ed+1] + memoHelper(nums, st, k-1, dp) + memoHelper(nums, k+1, ed, dp));
        }
        dp[st][ed] = maxCoins;
        return dp[st][ed];
    }
    int maxCoins(vector<int>& nums) {
        // Inuition: Pop one bulloon first and connect the rest of two segments
        // Other inuition: Pop one bullon LAST and thw rest of two segments are connected to this bullon

        // edge case
        int n = nums.size();
        if(n == 1) return nums[0];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return memoHelper(nums, 1, n, dp);
    }
};