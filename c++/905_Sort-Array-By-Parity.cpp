class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lhs = 0, rhs = nums.size() - 1;
        while(lhs < rhs){
            if(nums[lhs] % 2 == 0) ++lhs;
            else {
                swap(nums[lhs], nums[rhs]);
                --rhs;
            }
        }
        return nums;
    }
};