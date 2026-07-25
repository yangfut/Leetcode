class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ops = 0, f = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            // pop out
            if(i >= k) f -= nums[i-k];

            int curr = nums[i] + f;
            if(curr % 2 == 0){
                ++f;
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
            ops += nums[i];
        }
        
        for(int i = n-1; i > n-k; --i) if(nums[i] == 1) return -1;
        return ops;
    }
};