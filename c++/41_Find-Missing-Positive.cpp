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

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number in its correct position, such that nums[i] = i + 1
        for(int i = 0; i < n; ++i){
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first position where the number is not i + 1
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) {
                return i + 1; // Return the missing positive integer
            }
        }

        // If all positions are correctly aligned, the missing number is n + 1
        return n + 1;
    }
};
