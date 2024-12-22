class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // result = total - the longest non-decreasing array
        int len_1 = 0, len_2 = 0, len_3 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                ++len_1;
            }else if(nums[i] == 2){
                len_2 = max(len_1, len_2) + 1;
            }else if(nums[i] == 3){
                len_3 = max(max(len_2, len_1), len_3) + 1;
            }
        }

        return nums.size() - max(max(len_1, len_2), len_3);
    }
};

class Solution {
    int memo[101][4];
    int memoization(vector<int> &nums, int currIdx, int prev){
        // termination
        if(currIdx == nums.size()) return 0;
        if(memo[currIdx][prev] != -1) return memo[currIdx][prev];
        
        //not pick
        int nottaken = memoization(nums, currIdx+1, prev);
        
        //pick
        int taken = 0;
        if(nums[currIdx] >= prev){
            taken = 1 + memoization(nums, currIdx+1, nums[currIdx]);
        }
        return memo[currIdx][prev] = max(taken, nottaken);
    }
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));

        // find the length of longest non-decreasing array
        return n - memoization(nums, 0, 0);
    }
};