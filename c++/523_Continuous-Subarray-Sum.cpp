class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen = {{0,-1}};
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            int curr_rem = sum%k;

            if(seen.count(curr_rem)){
                if(i - seen[curr_rem] >= 2) return true;
            }else{
                seen[curr_rem] = i;
            }
        }
        return false;
    }
};