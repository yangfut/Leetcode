class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //binary search
        int left=0, right=nums.size()-1;
        int mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1]) right=mid;
            else left=mid+1;
        }
        return left;
    }
};