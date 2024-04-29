class Solution {
public:
    //https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
    //lower bound -> return a index pointing to the first value which is not less than target
    //upper bound -> return a index pointing to the first value which is greater than target
    int lower_bound(vector<int>& nums, int target){
        int l=0, r=nums.size(), mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<target) l=mid+1;
            else r=mid;
        }
        return l;
    }

    int upper_bound(vector<int>& nums, int target){
        int l=0, r=nums.size(), mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid+1;
            else r=mid;
        }
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1, -1};
        //Find lower bound by binary search
        int lower=lower_bound(nums, target);

        //Find upper bound by binary search
        int upper=upper_bound(nums, target)-1;

        if(lower==nums.size()||nums[lower]!=target) return vector<int>{-1, -1};
        return vector<int>{lower, upper};
    }
};