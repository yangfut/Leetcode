class Solution {
public:
    int dpHelper(vector<int>& nums, vector<vector<int>>& dp, int l, int r, int k){
        if(k == 3) return nums[r] - nums[l];
        int n = nums.size(), offset = max(n-8, 0);

        // caching
        // r - offset is to map index r in nums to index r in dp, which is size in 8
        if(dp[l][r-offset] != -1) return dp[l][r-offset];

        int shift_r = dpHelper(nums, dp, l, r-1, k+1);
        int shift_l = dpHelper(nums, dp, l+1, r, k+1);

        dp[l][r-offset] = min(shift_r, shift_l);
        return dp[l][r-offset];
    }
    int dp_solution(vector<int>& nums){
        if(nums.size() <= 4) return 0;
        int n = nums.size(), k = 3;
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(2+2*k, vector<int>(2+2*k, -1));
        return dpHelper(nums, dp, 0, n-1, 0);
    }

    int bf_solution(vector<int>& nums){
        if(nums.size() <= 4) return 0;

        sort(nums.begin(), nums.end());

        int last = nums.size() - 1;
        // scenario#1
        int min_1 = min(nums[last-3] - nums[0], nums[last-2] - nums[1]);
        // scenario#2
        int min_2 = min(nums[last-1] - nums[2], nums[last] - nums[3]);
        return min(min_1, min_2);
    }
    int minDifference(vector<int>& nums) {
        // 2D DP with optimized memory
        // TC:O(N^2), SC: O(1)
        return dp_solution(nums);

        // Brut-force
        // TC: O(1), SC:O(1)
        // return bf_solution(nums);
    }
};