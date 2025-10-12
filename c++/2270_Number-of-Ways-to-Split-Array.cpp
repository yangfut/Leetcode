class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n);
        preSum.front() = nums.front();
        for(int i = 1; i < n; ++i){
            preSum[i] = preSum[i-1] + nums[i];
        }

        int validCount = 0;
        for(int i = 0; i < n-1; ++i){
            if(preSum[i] >= (preSum.back() - preSum[i])) ++validCount;
        }
        return validCount;
    }
};