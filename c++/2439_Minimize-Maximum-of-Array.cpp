class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size(), glbMax = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            int div = sum / (i+1);
            int rem = sum % (i+1);
            int currMax = (rem == 0) ? div : div + 1;
            glbMax = max(glbMax, currMax);
        }
        return glbMax;
    }
};