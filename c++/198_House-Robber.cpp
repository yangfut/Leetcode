class Solution {
public:
    int rob(vector<int>& nums) {
        int cur=nums[0], prev=0;

        for(int i=1;i<nums.size();i++){
            int new_max=max(prev+nums[i], cur);
            prev=cur;
            cur=new_max;
        }

        return cur>prev?cur:prev;
    }
};