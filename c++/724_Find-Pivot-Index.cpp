class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;
        for(int i = 0; i < n; ++i) totalSum += nums[i];

        int leftSum = 0;
        for(int l = 0; l < n; ++l){
            int rightSum = totalSum - leftSum - nums[l];
            if(leftSum == rightSum) return l;
            leftSum += nums[l];
        }
        return -1;
    }
};