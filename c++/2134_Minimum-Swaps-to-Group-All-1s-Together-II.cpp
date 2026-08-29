class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        // Sliding window
        for(int ele : nums) {
            if(ele == 1) ++cnt;
        }
        int wSize = cnt;
        cnt = 0;
        for(int i = 0; i < wSize; ++i){
            if(nums[i] == 1) ++cnt;
        }
        int minSwap = wSize - cnt;
        for(int i = wSize; i < 2*n; ++i){
            if(nums[(i-wSize) % n] == 1) --cnt;
            if(nums[i % n] == 1) ++cnt;
            minSwap = min(minSwap, wSize - cnt);
        }
        return minSwap;
    }
};