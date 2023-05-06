class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int ele : nums){
            sum+=ele;
        }
        if(target > sum || target < -sum) return 0;
        int diff = sum - target;

        vector<vector<int>>dp(nums.size(), vector<int>(diff+1, 0));
        dp[0][diff] = 1;
        if(diff - 2*nums[0]>=0)
            dp[0][diff - 2*nums[0]] += 1;

        for(int idx = 1; idx < nums.size(); ++idx){
            for(int d = diff; d>=0; --d){
                if(d + 2*nums[idx] <= diff){
                dp[idx][d] = dp[idx-1][d + 2*nums[idx]] + dp[idx-1][d];
                }else{
                    dp[idx][d] = dp[idx-1][d];
                }
            }
        }

        return dp[nums.size()-1][0];
    }
};
