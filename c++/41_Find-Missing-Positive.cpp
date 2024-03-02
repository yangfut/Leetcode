class Solution {
public:
    int set_sol(vector<int>&nums){
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int i=1;i<INT_MAX;i++){
            if(!s.count(i)) return i;
        }
        return -1;
    }

    int swap_sol(vector<int>&nums){
        //Place nums[i] into its corresponding index, which is nums[i]-1.
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<n&&nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==i+1) continue;
            return i+1;
        }
        return n+1;
    }
    int firstMissingPositive(vector<int>& nums) {
        //#1 Set
        //return set_sol(nums);

        //#1 Swap
        return swap_sol(nums);
    }
};