class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // place value at rhs to lhs if it's valid, then increment lhs
        // increment rhs in every iternation
        
        int lhs, rhs;
        int n = nums.size();
        if(n < 3) return n;
        for(lhs = 2, rhs = 2; rhs < n; ++rhs){
            if(nums[rhs] != nums[lhs-2]){
                nums[lhs++] = nums[rhs];
            }
        }
        return lhs;
    }
};