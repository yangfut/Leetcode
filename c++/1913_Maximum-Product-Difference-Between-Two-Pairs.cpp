class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, min1, max2, min2;
        int temp_max = 0, temp_min = INT_MAX;

        // find forward maximum and minimum
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > temp_max){
                temp_max = nums[i];
                max1 = i;
            }

            if(nums[i] < temp_min){
                temp_min = nums[i];
                min1 = i;
            }
        }

        // find 2nd forwared maximum and minimum
        temp_max = 0, temp_min = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > temp_max && i != max1){
                temp_max = nums[i];
                max2 = i;
            }
            if(nums[i] < temp_min && i != min1){
                temp_min = nums[i];
                min2 = i;
            }
        }
        return (nums[max1] * nums[max2]) - (nums[min1] * nums[min2]);
    }
};