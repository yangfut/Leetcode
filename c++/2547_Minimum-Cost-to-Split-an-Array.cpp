class Solution {
public:

    int backtrack(vector<int>& nums, int k, vector<int>& dp, int idx){
        // base cases
        if(idx == nums.size()) return 0;

        // caching
        if(dp[idx] != -1) return dp[idx];

        int distinct_count = 0;
        int result = INT_MAX;
        unordered_map<int,int> numCount;

        // iterate every proceding elements for split
        for(int i = idx; i < nums.size(); ++i){
            
            ++numCount[nums[i]];
            if(numCount[nums[i]] == 1) ++distinct_count;
            else if(numCount[nums[i]] == 2) --distinct_count;

            result = min(result, (k + (i - idx + 1 - distinct_count) + backtrack(nums, k, dp, i+1)));
        }

        return dp[idx] = result;

    }
    int minCost(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), -1);
        return backtrack(nums, k, dp, 0);
    }
};