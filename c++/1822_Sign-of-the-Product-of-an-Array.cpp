class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int count_negative_numbers = 0;
        for(int ele : nums){
            if(ele == 0) return 0;

            if(ele < 0) ++count_negative_numbers;
        }

        return (count_negative_numbers % 2 == 0) ? 1 : -1;
    }
};