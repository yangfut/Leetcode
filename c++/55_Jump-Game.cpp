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

class Solution {
public:
    // #1 DFS + Memoization
    // bool dfs(vector<int>& nums, int start, vector<int>& memo){
        
    //     // Base case
    //     if(start>=nums.size()-1) return true;
    //     if(memo[start]!=-1) return memo[start];

    //     int jump = nums[start];
    //     if(jump==0) return false;

    //     for(int next=start+1; next<=start+jump; ++next){
    //         if(dfs(nums, next, memo)){
    //             memo[start]=1;
    //             return true;
    //         }
    //     }
    //     memo[start]=0;
    //     return false;
    // }
    
    // bool canJump(vector<int>& nums) {
    //     vector<int>memo(nums.size(), -1);
    //     return dfs(nums, 0, memo);
    // }
    
    // #2 Dynamic Programming to find the maximum reach point
    bool canJump(vector<int>& nums) {
        int i=0;
        for(int reach=0; i<nums.size()&&i<=reach;++i){
            reach = max(reach, i+nums[i]);
        }

        return i==nums.size();
    }
};