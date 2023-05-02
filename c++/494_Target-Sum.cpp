class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      
	int n = nums.size();
	int sum = 0;
	for(int ele : nums){
	    sum += ele;
    }

    if(target < -sum || target > sum) return 0;

    int offset = sum;
    vector<vector<int>>dp(n, vector<int>(2*sum+1, 0));

    dp[0][nums[0]+offset]=1;
    dp[0][offset-nums[0]]+=1;

    for(int idx = 1; idx < n; idx++){
        for(int s=0; s <= sum+offset; s++){
            if(dp[idx-1][s]>0){
                dp[idx][s-nums[idx]] += dp[idx-1][s];
                dp[idx][s+nums[idx]] += dp[idx-1][s];
            }
        }
    }

    return dp[n-1][target+offset];
    }
};
