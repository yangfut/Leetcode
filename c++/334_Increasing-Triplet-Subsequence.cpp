class Solution {
public:
    bool two_arr_sol(vector<int>& nums){
        if(nums.size()<3) return false;


        int n=nums.size();
        vector<int>l_min(n);
        vector<int>r_max(n);

        //find minimum value starting from index 0
        l_min[0]=nums[0];
        for(int i=1;i<n;i++) l_min[i]=min(l_min[i-1], nums[i]);

        //find maximum value starting from index n-1
        r_max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) r_max[i]=max(r_max[i+1], nums[i]);

        //Go through 0->n-1 too see if nth element is greater than l_min[i] and smaller than r_max[i]
        for(int i=0;i<n;i++){
            if(nums[i]>l_min[i]&&nums[i]<r_max[i]) return true;
        }
        return false;
    }
    
    bool two_var_sol(vector<int>& nums) {
        if(nums.size()<3) return false;

        int n=nums.size();
        //first will track of first element of triplet
        int first=INT_MAX;

        //second will track of second element of triple
        int second=INT_MAX;

        for(int ele:nums){
            if(ele<=first){
                //smallest value before ele
                first=ele;
            }
            else if(ele<=second){
                //second smallest value before ele
                second=ele;
            } 
            else{
                //if ele reaches here, it's the third one
                return true;
            }
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        //#1 Two Arrays
        //TC:O(n), SC:O(n)
        //return two_arr_sol(nums);

        //#2 Two variables
        return two_var_sol(nums);
    }
};