class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // #1 0D Dynamic Programming(tabulation)
        int maxt = -10000, maxv = -10000;

        for(int& num : nums){
            maxt = max(maxt+num, num);
            maxv = max(maxt, maxv);
        }
        return maxv;
    }
};