class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,false);
        dp[0] = true;
        for(int i = 0; i <= n; ++i){
            // group in 2
            if(i >= 2 && dp[i-2]){
                if(nums[i-1] == nums[i-2]){
                    dp[i] = true;
                }
            }

            // group in 3
            if(i >= 3 && dp[i-3]){
                if(nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3]){
                    dp[i] = true;
                }

                if(nums[i-1] - nums[i-2] == 1 && nums[i-2]-nums[i-3] == 1){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};