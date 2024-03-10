class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size()-1;
        int pairs_count = 0;

        while(l<r){
            if(nums[l]+nums[r]<target){
                pairs_count += r - l;
                ++l;
            }else --r;
        }

        return pairs_count;
    }
};