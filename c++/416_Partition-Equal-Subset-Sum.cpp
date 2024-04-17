class Solution {
public:
    bool backtrackingHelper(vector<int>& nums, vector<vector<int>>& cache, int target, int idx){
        // base case
        if(target == 0) return true;
        if(idx == nums.size() || target < 0) return false;

        // Check if cache hits
        if(cache[idx][target] != -1) return 1 == cache[idx][target];

        // Pick
        bool take = backtrackingHelper(nums, cache, target-nums[idx], idx+1);

        // Not pick
        bool nottake = backtrackingHelper(nums, cache, target, idx+1);

        cache[idx][target] = take || nottake;
        return cache[idx][target];
    }
    
    bool backtracking_sol(vector<int>& nums){
        // Edge base
        if(nums.size() == 1) return false;
        int n = nums.size(), target = 0;
        
        for(int& ele : nums) target += ele;
        if(target%2) return false;
        
        target /= 2; //half of total sum
        vector<vector<int>> cache(n, vector<int>(target+1, -1));
        return backtrackingHelper(nums, cache, target, 0);
    }

    bool set_sol(vector<int>& nums){
        // Edge case
        if(nums.size() == 1) return false;

        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        
        if(target%2) return false;
        target /= 2; // target is the half of sum
        
        unordered_set<int> combSum;
        combSum.insert(0);

        // Store every possible sum from tail
        for(int idx = n-1; idx >= 0; --idx){
            unordered_set<int> new_combSum;
            for(auto& prev : combSum){
                if(prev+nums[idx] == target) return true;
                new_combSum.insert(prev+nums[idx]);
            }
            combSum.insert(new_combSum.begin(), new_combSum.end());
        }
        return false;

    }
    // Solution from ChatGPT
    // bool dp_sol(vector<int>& nums){
    //     int n = nums.size();
    //     int target = accumulate(nums.begin(), nums.end(), 0);

    //     if(target%2) return false;
    //     target /= 2;

    //     // Indicate the result of a specific sum
    //     vector<bool> combSum(target+1, false);
    //     combSum[0] = true;
    //     for(int& num : nums){
    //         for(int value = target; value >= num; --value){
    //             // Update new target by value - num
    //             combSum[value] = combSum[value] || combSum[value - num];
    //             if(combSum[target]) return true;
    //         }
    //     }
    //     return false;
    // }
    bool canPartition(vector<int>& nums) {
        // 1. Backtracking with cache
        return backtracking_sol(nums);

        // 2. Solution with Set
        // return set_sol(nums);

        // 3. DP
        // return dp_sol(nums);
    }
};