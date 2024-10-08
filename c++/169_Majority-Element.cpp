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

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count=0;

        for(int& ele:nums){
            // if match, ++count
            // if unmatch, --count
            // if unmatch and count is zero, swtich majority
            if(!count) majority = ele;
            count += (ele == majority) ? 1 : -1;
        }
        return majority;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj = INT_MIN;

        for(int ele : nums){

            if(!count) maj = ele;
            count = (maj == ele) ? count + 1 : count - 1;
        }
        return maj;
    }
};