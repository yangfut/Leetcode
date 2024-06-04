class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = 0;
        for(int idx = 0; idx < n; ++idx){
            if(k > 0 && nums[idx] < 0){
                nums[idx] = -nums[idx];
                --k;
            }
            sum += nums[idx];
        }

        sort(nums.begin(), nums.end());
        if(k % 2 == 1) return sum - (2*nums.front());
        return sum;
    }
};