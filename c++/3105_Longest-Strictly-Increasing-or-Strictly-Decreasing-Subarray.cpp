class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int maxLen = 1, n = nums.size(), currLen = 0;

        //0: draw, 1: postive, 2: negative, 3: undetermined
        for(int st = 0, ed = 1, dir = 3; ed < n; ++ed){
            if(dir == 3){
                if(nums[ed] - nums[st] > 0) dir = 1, currLen = 2;
                else if(nums[ed] - nums[st] == 0) dir = 0, currLen = 1;
                else dir = 2, currLen = 2;
                
                maxLen = max(maxLen, currLen);
                continue;
            }

            if((nums[ed] > nums[ed-1] && dir == 1) || (nums[ed] < nums[ed-1] && dir == 2)){
                ++currLen;
                maxLen = max(maxLen, currLen);
            }else{
                st = ed-1;
                --ed;
                dir = 3;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int inc = 1, dec = 1, maxLen = 1;
        for(int i = 1; i < n; ++i){
            int diff = nums[i] - nums[i-1];
            if(diff > 0){
                ++inc;
                dec = 1;
            }else if(diff < 0){
                ++dec;
                inc = 1;
            }else{
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));
        }
        return maxLen;
    }
};