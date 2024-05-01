class Solution {
public:
    int backtrack(vector<int>& nums, vector<int>& memo, int idx){
        // base case
        if(idx >= nums.size()-1) return 0;

        // caching
        if(memo[idx]!=-1) return memo[idx];

        int step = INT_MAX;
        for(int i = 1; i <= nums[idx]; ++i){
            step = min(step, backtrack(nums, memo, idx+i));
        }

        // unreachable
        if(step == INT_MAX) return memo[idx] = INT_MAX;

        return memo[idx] = 1 + step;
    }

    int backtrack_sol(vector<int>& nums){
        vector<int> memo(nums.size(), -1);
        return backtrack(nums, memo, 0);
    }

    int greedy_sol(vector<int>& nums){
        // Greey algorithm: do optimal choice at every iteration
        int n = nums.size();

        int jump = 0, distance = 0, maxDist = 0;

        // In this case, always take the jump with maximum distance
        for(int idx = 0; idx < n; ++idx){
            if(maxDist < idx){
                maxDist = distance;
                ++jump;
            }

            distance = max(distance, idx + nums[idx]);
        }

        return jump;
    }
    int jump(vector<int>& nums) {
        // #1 backtracking with memoization
        // TC: O(N), SC:O(N)
        // return backtrack_sol(nums);

        // #2 Greedy
        return greedy_sol(nums);
    }
};