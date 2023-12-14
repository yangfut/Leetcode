class Solution {
public:
    
    //Option#1: Majority counting
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = nums[0];
        for(int ele:nums){
            if(count==0)ans = ele;
            count += (ans == ele) ? 1 : -1; 
        }
        return ans;
    }

    //Option#2: Sorting and Counting
    /*
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int currentNumber = INT_MIN;
        int maxCount = 0;
        int maxNumber = nums[0];
        for(int ele:nums){
            if(currentNumber==ele){
                count++;
            }else{
                if(count > maxCount){
                    maxCount = count;
                    maxNumber = currentNumber;
                }
                count = 1;
                currentNumber = ele;
            }
        }

        return count > maxCount ? currentNumber : maxNumber;
    }
    */
};