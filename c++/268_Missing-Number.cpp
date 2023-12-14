class Solution {
public:
    //Option#1: Math
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int actualSum = 0;
        int estimatedSum = (n+1)*n/2;

        for(int ele:nums){
            actualSum += ele;
        }

        return estimatedSum - actualSum;
    }
    
    //Option#2: Hash Table
    /*
    int missingNumber(vector<int>& nums) {
        vector<int>hashTable(nums.size()+1, 0);

        for(int ele:nums){
            hashTable[ele] = 1;
        }

        int idx;
        for(idx=0; idx<=nums.size(); idx++){
            if(hashTable[idx]==0) return idx;
        }
        return idx;
    }
    */

    //Option#3: Swap
    /*
    int missingNumber(vector<int>& nums) {
        
        int idx=0;
        while(idx<nums.size()){
            if(nums[idx]<idx){
                swap(nums[idx], nums[nums[idx]]);
            }else{
                idx++;
            }
        }
        
        for(idx=0; idx<nums.size(); idx++){
            if(nums[idx]!=idx){
                break;
            }
        }
        return idx;
    }
    */
};