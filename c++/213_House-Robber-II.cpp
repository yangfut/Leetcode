class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        //Pick the first element and ignore the last one
        int prev=0, cur=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            int new_max=max(prev+nums[i], cur);
            prev=cur;
            cur=new_max;
        }
        int max1=(cur>prev)?cur:prev;

        //Ignore the first element
        prev=0, cur=nums[1];
        for(int i=2;i<nums.size();i++){
            int new_max=max(prev+nums[i], cur);
            prev=cur;
            cur=new_max;
        }
        int max2=(cur>prev)?cur:prev;
        return(max1>max2)?max1:max2;
    }
};