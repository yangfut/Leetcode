class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for(int num : nums){
            count = (num == 1) ? count + 1 : 0;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};