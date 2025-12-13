class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = 0, prev = 0, maxSum = 0;
        for(int num : nums){
            if(num <= prev){
                currSum = 0;
            }

            currSum += num;
            maxSum = max(maxSum, currSum);
            prev = num;
        }
        return maxSum;
    }
};