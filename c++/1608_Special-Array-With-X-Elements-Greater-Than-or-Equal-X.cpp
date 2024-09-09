class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            // Skip duplicated numbers or elements that doesn't meet the criteria
            if( (i > 0 && nums[i] == nums[i-1]) || nums[i] < n-i) continue;

            // Criteria for special number X
            if( i == 0 || n-i > nums[i-1]) return n-i;
        }

        // No speical number is found
        return -1;
    }
};