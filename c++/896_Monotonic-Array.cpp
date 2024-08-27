class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i;
        bool inc = true;
        bool dec = true;
        int n = nums.size();
        
        // check dec condition
        for(i = 0; i < n-1; ++i){
            if(nums[i+1] > nums[i]){
                dec = false;
            }
        }

        // check inc condition
        for(i = 0; i < n-1; ++i){
            if(nums[i+1] < nums[i]){
                inc = false;
            }
        }
        return inc || dec;
        
    }
};