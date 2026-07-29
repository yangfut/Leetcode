class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // for abs(), find minimum and maximum at the same time
        int absMax = 0, currMin = 10000, currMax = -10000;
        for(int num : nums){
            // Postive Kadane's algorithm
            currMax = max(currMax + num, num);
            // Negative Kadane's algorithm
            currMin = min(currMin + num, num);
            absMax = max(absMax, max(abs(currMax), abs(currMin)));
        }
        return absMax;
    }
};