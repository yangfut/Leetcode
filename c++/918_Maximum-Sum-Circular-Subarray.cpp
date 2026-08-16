class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Two scenarios: (1) wrap (2) non-wrap
        // For (2), find maximum subarray via Kadanes's algorithm
        // For (1), findm minimum subarray via Kadanes's algorithm. Since maximum subarray is wrapped, so minimum array must be unwrapped
        int n = nums.size();
        int currMax = 0, currMin = 0;
        int globalMax = INT_MIN, globalMin = INT_MAX;

        int totalSum = 0;
        for(int val : nums) totalSum += val;
        for(int val : nums){

            // Maximum Kadane's algorithm
            currMax = max(currMax, 0) + val;
            globalMax = max(globalMax, currMax);

            // Minimum Kadane's algorithm
            currMin = min(0, currMin) + val;
            globalMin = min(globalMin, currMin);
        }

        if(globalMax < 0) return globalMax;

        // if all negative, totalSum - globalMin must be zero
        return max(globalMax, totalSum - globalMin);
    }
};