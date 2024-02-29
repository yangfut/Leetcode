class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //Vector to store the maximum index that this node can reach
        //dp[i]=max(dp[i-1], i+nums[i])
        vector<int>dp(nums.size(), 0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            //If maximum possible index can't reach the current node, then break
            if(dp[i-1]<i) break;
            dp[i]=max(dp[i-1], i+nums[i]);
        }
        return dp[nums.size()-1]>=nums.size()-1;
    }
};