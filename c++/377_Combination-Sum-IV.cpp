class Solution {
public:
    uint32_t backtrack(vector<int>& nums, int target, vector<uint32_t>& memo){
        if(target == 0) return 1;

        if(memo[target] != UINT32_MAX) return memo[target];

        uint32_t comb = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > target) continue;
            uint32_t currComb = backtrack(nums, target - nums[i], memo);
            comb += currComb;
        }
        return memo[target] = comb;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> memo(target+1,UINT32_MAX);
        return (int)backtrack(nums, target, memo);
    }
};

// Time Limit Exceeded
// nums = [2,1,3], target = 35
class Solution {
public:
    int backtrack(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;

        uint32_t comb = 0;
        for(int i = 0; i < nums.size(); ++i){
            uint32_t currComb = backtrack(nums, target - nums[i]);
            comb += currComb;
        }
        return comb;

    }
    int combinationSum4(vector<int>& nums, int target) {
        return backtrack(nums, target);
    }
};