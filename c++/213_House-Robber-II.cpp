class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        //1-dimensional DP
        vector<int>dp1(nums.size()+2, 0);
        vector<int>dp2(nums.size()+2, 0);
        int ans1, ans2;
        int temp;
        //Senario I - Ignore first element
        temp = nums[0];
        nums[0] = 0;
        for(int idx = 2; idx < nums.size() + 2; ++idx){
            dp1[idx] = max((dp1[idx-2] + nums[idx-2]), dp1[idx-1]);
        }
        ans1 = dp1.back();
        nums[0] = temp;

        //Senario II - Ignore last element
        nums[nums.size()-1] = 0;
        for(int idx = 2; idx < nums.size() + 2; ++idx){
            dp2[idx] = max((dp2[idx-2] + nums[idx-2]), dp2[idx-1]);
        }
        ans2 = dp2.back();
        return max(ans1, ans2);
    }
};