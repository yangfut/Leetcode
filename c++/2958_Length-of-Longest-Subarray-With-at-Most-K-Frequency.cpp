class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int> numsCount;
        int l = 0, r = 0, n = nums.size(), maxLen = 0;

        // sliding windows to count maximum length of valid subarray
        while(r < n){
            ++numsCount[nums[r]];

            while(numsCount[nums[r]] > k){
                --numsCount[nums[l]];
                ++l;
            }

            maxLen = max(maxLen, r-l+1);
            ++r;
        }
        return maxLen;
    }
};