class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;

        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){
                //Check if left leaf is in ascending order. If yes, search in left
                //Since mid can't be target, so high=mid-1 and low=mid+1 (exclude mid)
                if(nums[mid]>target && nums[low]<=target) high=mid-1;
                else low=mid+1;
            }else{
                //Check if right leaf is in ascending order. If yes, search in right
                //Since mid can't be target, so low=mid+1 and high = mid-1 (exclude mid)
                if(nums[mid]<target && nums[high]>=target) low=mid+1;
                else high=mid-1;
            }
        }
        return (nums[low]==target)?low:-1;
    }
};