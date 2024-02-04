class Solution {
public:
    int dfs(vector<int>&nums, int prev, int idx, vector<int>&cache){
        // Boundary condition
        if(idx==nums.size()) return 0;

        // Check if optimal solution exists
        if(cache[prev]!=0) return cache[prev];

        // with
        int with=0;
        if(nums[idx]>nums[prev]){
            with=(cache[idx]!=0)? cache[idx]:1+dfs(nums,idx,idx+1,cache);
            cache[idx]=with;
        }
        // without
        int without=dfs(nums,prev,idx+1,cache);

        // Store optimal solution to cache
        cache[prev]=max(with,without);
        return cache[prev];
    }
    int dfs_solution(vector<int>& nums){
        
        // TC:O(N^2)
        // SC:O(N)
        int ans=0;
        vector<int> cache(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            if(cache[i]==0) cache[i] = dfs(nums, i, i+1, cache);
            if(cache[i]>ans) ans=cache[i];
        }
        return 1+ans;
    }

    int dp_solution(vector<int>&nums){
        vector<int>dp(nums.size(),1);
        int ans=0;
        for(int i=1; i<nums.size();i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        for(int ele:dp) ans=(ele>ans)?ele:ans;
        return ans;
    }

    int stl_based_solution(vector<int>&nums){
        if(nums.size()==0) return 0;
        // If incoming element is greater than the last element of S, we extend S
        // Insert and replace the smallest element that is not smaller than the incoming element
        vector<int>vec;
        vec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>vec.back()) vec.push_back(nums[i]);
            else{
                int idx=lower_bound(vec.begin(), vec.end(), nums[i])-vec.begin();
                nums[idx]=nums[i];
            }
        }
        return vec.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        
        // #1 DFS + Memorization
        // TC:O(N^2), SC:O(N)
        // return dfs_solution(nums);
        
        // #2 Dynamic Programming
        // TC:O(N^2) SC:O(N)
        return dp_solution(nums);

        // #3 Genius Solution
        // TC:O(NlogN) SC:O(N)
        return stl_based_solution(nums);

    }
};