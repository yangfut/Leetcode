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

class Solution {
public:
    int memoHelper(vector<int>& nums, int target, int result, int idx, vector<vector<int>>& dp, int sum){
        
        //bottom-left to top-right
        if(idx == nums.size()){
            if(target == result) return 1;
            else return 0;
        }
        if(dp[result+sum][idx]!=-1) return dp[result+sum][idx];

        dp[result+sum][idx] = memoHelper(nums, target, result-nums[idx], idx+1, dp, sum) 
                            + memoHelper(nums, target, result+nums[idx], idx+1, dp, sum);

        return dp[result+sum][idx];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int& num : nums) sum+=num;

        if(target > sum || target < -sum) return 0;

        vector<vector<int>> dp(2*sum+1, vector<int>(n, -1));
        return memoHelper(nums, target, 0, 0, dp, sum);
    }
};